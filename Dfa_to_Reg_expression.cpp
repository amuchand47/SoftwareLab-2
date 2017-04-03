#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;

char starting_state;
vector <char> F;
vector <char> Q;
vector <char> E;
char tran[10][10];

struct trans      // New
{
    int k;
    vector <string> v[10];
};

trans R[10];

string Rij(int i,int j,int k)   //R^k(i,j)
{
    vector <char> ans;
    string ans1;
    if(k==0)
    {
        if(i==j)
        {
        ans.push_back('e');
        if(tran[i+1][j+1]!='N')
        {
            ans.push_back('+');
            ans.push_back(tran[i+1][j+1]);
        }
        }
        else
        {
         ans.push_back(tran[i+1][j+1]);
        }

     string s(ans.begin(),ans.end());
     //cout<<i+1<<" "<<j+1<<" "<<s<<" ";
    return s;
    }

    else if(k>0)
    {
     int ct=0;
     if(R[k-1].v[i][j].compare("N")!=0)
     {
         ans1.append("(");
         ans1.append(R[k-1].v[i][j]);
         ans1.append(")");
         ct=1;
        // cout<<ans1<<"First";
     }

     if(R[k-1].v[i][k].compare("N")!=0 && R[k-1].v[k][k].compare("N")!=0 && R[k-1].v[k][j].compare("N")!=0)
     {
         if(ct==1)
         {
             ans1.append("+");
         }
         ans1.append("(");

         ans1.append("(");
         ans1.append(R[k-1].v[i][k]);
         ans1.append(")");

         ans1.append("(");
         ans1.append(R[k-1].v[k][k]);
         ans1.append(")");
         ans1.append("*");

         ans1.append("(");
         ans1.append(R[k-1].v[k][j]);
         ans1.append(")");

         ans1.append(")");
        //cout<<i+1<<" "<<j+1<<" "<<ans1<<" ";
       return ans1;
     }
}
}
int main()
{

    ifstream fin;
    fin.open("input.txt");

    char line[10];
    int t=0;  //total transitions
    while ( !fin.eof() )
     {

        fin>>line;

        if(line[0]=='Q')
        {
            for(int i=3;i<strlen(line);i=i+2)
            {
                if(line[i]!=',' || line [i]!='}')
                    Q.push_back(line[i]);
            }


          for(int i=0;i<=Q.size();i++)
          {
              for(int j=0;j<=Q.size();j++)   //Initializing trans
                tran[i][j]='N';
          }

        }

        else if(line[0]=='E')
        {
            for(int i=3;i<strlen(line);i=i+2)
            {
                if(line[i]!=',' || line[i]!='}')
                    E.push_back(line[i]);
            }
        }

        else if(line[0]=='S')
        {
         tran[ line[2]-'0'][ line[8]-'0']=line[4];
        /*
          int c1=0,c2=0,c3=0;
          for(int i=0;i<E.size();i++)
          {
              if(line[0]==E[i])
                c1++;
              if(line[8]==E[i])
                c2++;
          }
          for(int i=0;i<Q.size();i++)
          {
              if(line[4]==Q[i])
                c3++;
          }

          if(c1!=0 && c2!=0 && c3!=0)
          tran[ line[2]-'0'][ line[8]-'0']=line[4];
          else
          {
              cout<<"Invalid transition \n";
              cout<<"Please enter valid transition again";
              return 0;
          }
          */
        }

        else if(line[0]=='q')
         {
             starting_state=line[3];
         }

         else if (line [0]=='F')
         {
             for(int i=3;i<strlen(line);i=i+2)
             {
                 if(line[i]!=',' || line [i]!='}')
                    F.push_back(line[i]);
             }
         }
     }

    fin.close();

   /*
    for(int i=0;i<Q.size();i++)
    cout<<Q[i]<<" ";
    cout<<endl;
    for(int i=0;i<E.size();i++)
         cout<<E[i]<<" ";
    cout<<endl;

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cout<<tran[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
  */
  int c=1;
  for(int i=0;i<Q.size();i++)
  {
     R[i].k=c;
     c++;
     for(int j=0;j<Q.size();j++)
     {
         for(int k=0;k<Q.size();k++)
         {
             string s;   //
             s=Rij(j,k,i);
            // cout<<j+1<<" "<<k+1<<" "<<s<<" ";
             R[i].v[j].push_back(s);
         }
        // cout<<endl;
     }
  }

 cout<<"Go to the output file for Regular Expression"<<endl;
  ofstream fout("output.txt");

  fout<<"Rij Table "<<endl;

  for(int i=0;i<Q.size();i++)
  {

     for(int j=0;j<Q.size();j++)
     {
         for(int k=0;k<Q.size();k++)
         {
             fout<<R[i].v[j][k];
             fout<<" ";
         }
         fout<<endl;
     }
  }
  fout<<endl;
  fout<<"Regular Expression is \n";
  fout<<R[Q.size()-1].v[0][Q.size()-1];
  fout.close();
    return 0;
}
