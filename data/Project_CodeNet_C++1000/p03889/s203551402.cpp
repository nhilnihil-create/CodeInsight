#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s,x,k;
int len;
int main()
{
    cin>>s;
    x=s;
    len=s.length();
    for(int i=0;i<=(len/2)-1;i++)
    {
        swap(s[i],s[len-1-i]);
    }

    for(int i=0;i<len;i++)
    {
        if(s[i]=='b')
        {
            s[i]='d';
            continue;
        }
        if(s[i]=='d')
        {
            s[i]='b';
            continue;
        }
        if(s[i]=='p')
        {
            s[i]='q';
            continue;
        }
        if(s[i]=='q')
        {
            s[i]='p';
            continue;
        }
    }
    if(x==s)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}