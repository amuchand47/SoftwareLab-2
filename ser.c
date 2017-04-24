#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

#define N 3
char Board[N][N];

void Show()
{
printf("Current state of Board \n");
   for(int i=0;i<N;i++)
    {
     printf("\t");
      for(int j=0;j<N;j++)
     printf("%c ",Board[i][j]);
      printf("\n");
    }
}

int Check_Winner()
{
   int flag=-1;
   for(int i=0;i<3;i++)
    {
       if( (Board[i][0]==Board[i][1] && Board[i][1]==Board[i][2] && Board[i][2]=='X')
        ||  ( Board[0][i]==Board[1][i] && Board[1][i]==Board[2][i] && Board[2][i]=='X')
        || ( Board[0][0]==Board[1][1] && Board[1][1]==Board[2][2] && Board[1][1]=='X')
        || (Board[0][2]==Board[1][1] && Board[1][1]==Board[2][0] && Board[1][1]=='X') )
        {
        	flag=0;
        	break;
        }
        else if( (Board[i][0]==Board[i][1] && Board[i][1]==Board[i][2] && Board[i][2]=='O')
        ||  ( Board[0][i]==Board[1][i] && Board[1][i]==Board[2][i] && Board[2][i]=='O')
        || ( Board[0][0]==Board[1][1] && Board[1][1]==Board[2][2] && Board[1][1]=='O')
        || (Board[0][2]==Board[1][1] && Board[1][1]==Board[2][0] && Board[1][1]=='O') )
        {
        	flag=1;
        	break;
        }
    }

    return flag;
}


void Change_Board(int pos, char m)
{
   pos=pos-1;
   Board[pos/3][pos%3]=m;
   Show();
}




int main(int argc, char const *argv[])
{

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    bind(server_fd, (struct sockaddr *)&address,sizeof(address));

      listen(server_fd, 3);

      new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

   for(int i=0;i<3;i++)
   {
     valread = read( new_socket , buffer, 1024);
      printf("%s\n",buffer );
     int m=rand()%9;
     printf("My move is \n");
     printf("%d",m);
     int n=htonl(m);
     write(new_socket, &n, sizeof(n));
   }

    return 0;
}

