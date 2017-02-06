#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int Power(int t)
{
    int r=1;
    for(int i=1;i<=t;i++)
        r=r*2;
 return r;
}

vector <char> Q;   // finite states
vector <char> E;    // Alphabets
char starting_state;
vector <char> final_states;

vector <char> Q_d;       // for dfa
vector <char> E_d;
char starting_state_d;
vector <char> final_states_d;

struct trans      //Transition
{
    char state;  // a b c any one state
    char trns;      // move 0 or 1
    vector <char> move;  // After moving at 0 or 1 to next states
};

struct dfa_trans
{
    vector <char> state;  // a b c any one state
    char trns;      // move 0 or 1
    vector <char> move;  // After moving at 0 or 1 to next states
};

trans T[20];

int Nfa_check_count=0;

vector <char> Union(vector <char> & A, vector <char> &B)
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector <char> C(A.size()+B.size());
    vector <char> :: iterator it=set_union(A.begin(),A.end(),B.begin(),B.end(),C.begin());
    C.resize(it-C.begin());
 return C;
}

int main()
{
    ifstream fin;
    fin.open("P2.txt");


    string line;
    int t=0;  //total transitions
    while ( !fin.eof() )
     {

        fin>>line;

        if(line[0]=='Q')
        {
            for(int i=3;i<line.size();i=i+2)
            {
                if(line[i]!=',' || line [i]!='}')
                    Q.push_back(line[i]);
            }
        }

        else if(line[0]=='E')
        {
            for(int i=3;i<line.size();i=i+2)
            {
                if(line[i]!=',' || line[i]!='}')
                    E.push_back(line[i]);
            }
        }
        else if(line[0]=='S')
        {
           // cout<<"chand";
            T[t].state=line[2];
            T[t].trns=line[4];
            for(int i=8;i<line.size()-1;i++)
            {
                T[t].move.push_back(line[i]);
            }
         t++;
        }
        else if(line[0]=='q')
         {
             starting_state=line[3];
         }
         else if (line [0]=='F')
         {
             for(int i=3;i<line.size()-1;i++)
                final_states.push_back(line[i]);
         }
     }

    for(int i=0;i<Q.size();i++)
        cout<<Q[i]<<" ";
    cout<<endl;
    for(int i=0;i<E.size();i++)
         cout<<E[i]<<" ";
    cout<<endl;

    for(int i=0;i<t;i++)
    {
        cout<<"S("<<T[i].state<<",";
        cout<<T[i].trns<<"):{";

        if(T[i].move.size()>=2)
            Nfa_check_count++;

        for(int j=0;j<T[i].move.size();j++)
           {
               cout<<T[i].move[j]<<"";
           }
       cout<<"}";
     cout<<endl;
    }

    fin.close();
   cout<<endl;

   if(Nfa_check_count>0)
    cout<<"Given Automata is NFA";
   else
    cout<<"Given Automata is not a NFA";

   dfa_trans Tdf[2*Power(Q.size())];

  //  Q_d=Q;
  //  E_d=E;
  //  starting_state_d=starting_state;
  //  final_states_d=final_states;

   for(int i=0;i<t;i++)
   {

     char l=T[i].state;
      Tdf[i].state.push_back(l);
      Tdf[i].trns=T[i].trns;

      for(int j=0;j<T[i].move.size();j++)
           {
               Tdf[i].move.push_back(T[i].move[j]);
           }
   }

      cout<<endl;
   /*
   for(int i=0;i<t;i++)
    {

        cout<<"S(";
        for(int j=0;j<Tdf[i].state.size();j++)
        cout<<Tdf[i].state[j]<<",";

        cout<<Tdf[i].trns<<"):{";

        for(int j=0;j<Tdf[i].move.size();j++)
           {
               cout<<Tdf[i].move[j]<<"";
           }
       cout<<"}";
     cout<<endl;
    }
   int s=0;
   */

   vector <char> A;
   vector <char> B;
   vector <char> c;
   for(int i=t;i<16;i++)
   {

      if(i==6)
      {
          Tdf[i].state.push_back(Q[0]);   // 0 trns case
          Tdf[i].state.push_back(Q[1]);
           Tdf[i].trns='0';
           A=T[0].move;
           B=T[2].move;


        c=Union(A,B);
        Tdf[i].move=c;   // 6th

        Tdf[i+1].state.push_back(Q[0]);   // 1 trns case
          Tdf[i+1].state.push_back(Q[1]);
        Tdf[i+1].trns='1';

          A=T[1].move;
          B=T[3].move;

        c=Union(A,B);
        Tdf[i+1].move=c;   //7th
      }
       else if(i==7)
       {
           Tdf[i+1].state.push_back(Q[0]);   // 0 trns case
          Tdf[i+1].state.push_back(Q[2]);
          Tdf[i+1].trns='0';

           A=T[0].move;
           B=T[4].move;


        c=Union(A,B);
        Tdf[i+1].move=c;   // 8th

        Tdf[i+2].state.push_back(Q[0]);   // 1 trns case
          Tdf[i+2].state.push_back(Q[2]);
         Tdf[i+2].trns='1';

          vector <char> A=T[1].move;
          vector <char> B=T[5].move;

        c=Union(A,B);
        Tdf[i+2].move=c;  // 9th
       }
     else if(i==8)
     {
          Tdf[i+2].state.push_back(Q[1]);   // 0 trns case
          Tdf[i+2].state.push_back(Q[2]);
           Tdf[i+2].trns='0';

          A=T[2].move;
          B=T[4].move;

        c=Union(A,B);
        Tdf[i+2].move=c;   // 10th

        Tdf[i+3].state.push_back(Q[1]);   // 1 trns case
          Tdf[i+3].state.push_back(Q[2]);
          Tdf[i+3].trns='1';

          A=T[3].move;
          B=T[5].move;

        c=Union(A,B);
        Tdf[i+3].move=c;   //11th
     }
     else if(i==9)
     {
         Tdf[i+3].state.push_back(Q[0]);   // 0 trns case
         Tdf[i+3].state.push_back(Q[1]);
         Tdf[i+3].state.push_back(Q[2]);
         Tdf[i+3].trns='0';

          A=T[1].move;
          B=T[2].move;

        c=Union(A,B);
        Tdf[i+3].move=c;   // 12th

        Tdf[i+4].state.push_back(Q[0]);   // 1 trns case
        Tdf[i+4].state.push_back(Q[1]);
        Tdf[i+4].state.push_back(Q[2]);
        Tdf[i+4].trns='1';

          A=T[1].move;
          B=T[2].move;

        c=Union(A,B);
        Tdf[i+4].move=c;   //13th
     }
     else
     {
            break;
     }

      }

   for(int i=0;i<14;i++)
    {

        cout<<"S(";
        for(int j=0;j<Tdf[i].state.size();j++)
        cout<<Tdf[i].state[j]<<",";

        cout<<Tdf[i].trns<<"):{";

        for(int j=0;j<Tdf[i].move.size();j++)
           {
               cout<<Tdf[i].move[j]<<"";
           }
       cout<<"}";
     cout<<endl;
    }


    return 0;
}
