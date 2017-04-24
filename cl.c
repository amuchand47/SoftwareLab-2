#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

#define N 3
char Board[N][N];

void Initialise()
{
  for(int i=0;i<N;i++)
   {
     for(int j=0;j<N;j++)
       Board[i][j]='B';
   }
}

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



int main()
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));


  printf("Tic Tac Toe Game \n \n");
  Initialise();
  Show();
  char client='O',server='X';
  printf("Enter the move for client and server \n");

  int move;
  int no_win=0;
   for(int i=0;i<9;i++)
     {

          if(i%2==0)
           {
              printf("Enter the client move \n");
              scanf("%d",&move);
              if(Board[(move-1)/3][(move-1)%3]=='B' && (move>=1 && move<=9))
              Change_Board(move,client);
              else
              {
              printf("Invalid move \n Try again with valid move ");
              return ;
              }
           }
         else
           {
              printf("Server move is \n");
              char m[50]="Please server Enter your move \n";
              send(sock, m,strlen(m),0);
              int move;
              int received_int = 0;
              int return_status;
              return_status = read(sock, &received_int, sizeof(received_int));
               move=ntohl(received_int);
              if(move==0)
               move=1;
              printf("%d \n",move);
              if(Board[(move-1)/3][(move-1)%3]=='B' && (move>=1 && move<=9))
              Change_Board(move,server);
              else
              {
               printf("Invalid move \n Try Again with valid move");
               return ;
              }
            }

       if(Check_Winner()==0)
        {
         no_win=1;
         printf("Server won the game");
         break;
        }
       else if(Check_Winner()==1)
       {
         no_win=1;
         printf("Client won the game");
         break;
       }
     }
   if(no_win!=1)
    printf("Game draw");


    return 0;
}

