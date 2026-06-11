#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    cin>>a;
    b=a;
    for(int i=0;i<a.size()/2;++i)swap(a[a.size()-1-i],a[i]);
    for(int i=0;i<a.size();++i)
    {
        if(a[i]=='b')a[i]='d';
        else if(a[i]=='d')a[i]='b';
        else if(a[i]=='p')a[i]='q';
        else if(a[i]=='q')a[i]='p';
    }
    if(a==b) cout<<"Yes";
    else cout<<"No";
}