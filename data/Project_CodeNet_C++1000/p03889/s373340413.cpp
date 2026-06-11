#include<bits/stdc++.h>
using namespace std;
string s,b;
int main()
{
    cin>>s;
    int len=s.length();
    b=s;
    reverse(s.begin(),s.end());
    if(len&1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        if(b[i]=='b')b[i]='d';
        else if(b[i]=='d')b[i]='b';
        else if(b[i]=='p')b[i]='q';
        else b[i]='p';
    }
    if(b==s)
    cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
 } 