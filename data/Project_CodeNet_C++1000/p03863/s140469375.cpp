#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
    cin>>s;
    long long len=s.size();
    if(s[0]==s[len-1])
    {
        if(len%2==1) 
        {
            cout <<"Second";
        }
        else 
        {
            cout <<"First";
        }
    }
    else
    {
        if(len%2==1)
        {
            cout << "First\n";
        }
        else
        {
            cout << "Second\n";
        }
    }
    return 0;
}