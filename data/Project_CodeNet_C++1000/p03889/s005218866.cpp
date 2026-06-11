#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a;
    b=a;
    reverse(a.begin(),a.end());
    for(register int i=0;i<a.size();++i)
    {
        if(a[i]=='b')
            a[i]='d';
        else if(a[i]=='d')
            a[i]='b';
        else if(a[i]=='p')
            a[i]='q';
        else if(a[i]=='q')
            a[i]='p';
    }
    if(a==b)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}