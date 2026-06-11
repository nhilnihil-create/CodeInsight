// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string a;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>a;
    string b=a;
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();++i)
    {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    if(a==b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}