#include<algorithm>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;

bool validity_of_string(string str ,string reg_exp)            /* STANDARD REGEX FORM */
{                                                                // (b).(a+b)*.(ab)*    // (a)*.(ab).(b)*
    bool star=false,dot=false,plus=false;

    star=contains_star(str);
    dot=contains_dot(str);
    plus=contains_plus(str);

    if(str[1]!=reg_exp[0] && reg_exp[])
    {
        return true ;
    }
 return false;
}


bool contains_star(string &s)
{
    if (s.find('*') != string::npos)
    {
        return true;
    }
    return false;
}

bool contains_dot(string s)
{
    if(s.find('.')  != string::npos)
    {
        return true;
    }
    return false;
}

bool contains_plus(string s)
{
    if(s.find('+') != string::npos)
    {
        return true;
    }
 return false;
}


int count_alphabet_A(string str)
{
   size_t n = std::count(str.begin(), str.end(), 'a');
   return n;
}

int count_alphabet_B(string str)
{
    size_t n = std::count(str.begin(), str.end(), 'b');
    return n;
}


int main()
{
    cout<<"Enter the regular Expression \n";           // STANDARD REGEX FORM  // (b).(a+b)*.(ab)*    // (a)*.(ab).(b)*
    string reg_exp;
    cin>>reg_exp;

    cout<<"Matched string with the given regular expressions are "<<endl;
    ifstream fin;
    fin.open("input.txt");

    while(!fin.eof())
    {
        string str;
        fin>>str;
       if(validity_of_string(reg_exp,str))
            cout<<str<<endl;
    }

   fin.close();
    return 0;
}
