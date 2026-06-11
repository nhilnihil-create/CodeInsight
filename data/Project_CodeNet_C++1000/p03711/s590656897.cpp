#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ll a,b,c,d,e=0,f=0,j,i;
string s,ss;
    map<ll,ll>m,n;
    m[1]=1;m[3]=1;m[5]=1;m[7]=1;
    m[8]=1;m[10]=1;m[12]=1;
    n[4]=1;n[6]=1;n[9]=1;n[11]=1;
    cin>>a>>b;
    if(m[a]==1&&m[b]==1)cout<<"Yes\n";
else if(n[a]==1&&n[b]==1)cout<<"Yes\n";
else cout<<"No\n";
    
}