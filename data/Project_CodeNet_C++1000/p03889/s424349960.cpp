#include<bits/stdc++.h>
using namespace std;
string st;
char ch[100010];
long long len;
int main()
{
    cin>>st;
    len=st.size();
    for(int i=0;i<st.size();i++)
    {
        ch[len-i-1]=st[i];
        if(st[i]=='b')ch[len-i-1]='d';
        if(st[i]=='d')ch[len-i-1]='b';
        if(st[i]=='p')ch[len-i-1]='q';
        if(st[i]=='q')ch[len-i-1]='p';
    }
    for(int i=0;i<len;i++)
        if(ch[i]!=st[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    cout<<"Yes"<<endl;
    return 0;
}