#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int l[1005],r[1005];
int p1,p2,now;
void solve(ll x)
{
    //cout<<x<<endl;
    if(x==1)return ;
    if(x%2==1)l[++p1]=++now,x--;
    r[++p2]=++now;
    solve(x/2);
}
int main()
{
    cin>>n;
    solve(n+1);
    printf("%d\n",now*2);
    for(int i=1;i<=p1;i++)cout<<now-l[i]+1<<' ';
    for(int i=p2;i>=1;i--)cout<<now-r[i]+1<<' ';
    for(int i=1;i<=now;i++)cout<<i<<' ';
    return 0;
}
