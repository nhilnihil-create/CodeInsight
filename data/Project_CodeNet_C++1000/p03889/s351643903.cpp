#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int ln,i;
string st,ts;

int main()
{
    cin>>st;
    ln=st.size();
    for(i=0; i<ln; i++)
    {
        if(st[i]=='b')
            ts='d'+ts;
        if(st[i]=='d')
            ts='b'+ts;
        if(st[i]=='p')
            ts='q'+ts;
        if(st[i]=='q')
            ts='p'+ts;        
    }
    if(st==ts)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}