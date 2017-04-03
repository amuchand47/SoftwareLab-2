#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    while(1)
    {
    string str;
    cout<<"Enter word "<<endl;
    cin>>str;
    ifstream fin;
    fin.open("dictionary.txt");

    string ch;
    int count=0;
    cout<<"Suggested words are "<<endl;
    while(!fin.eof() && count<=10)
    {
         int c=0;
         fin>>ch;
         for(int i=0;i<str.size();i++)
         {
             if(str[i]==ch[i])
              c++;
         }
         if(c==str.size())
         {
             cout << ch<<endl;
             count++;
         }

    }
     fin.close();
    }
    return 0;
}
