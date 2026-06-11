#include<bits/stdc++.h>
using namespace std;
int dp[45][403][406];
int a[45],b[45],c[45];
int Ma,Mb;
int n;
#define inf 100000000
int call(int i,int x,int y)
{
//    cout<<i<<" "<<x<<" "<<y<<endl;
    if(x>0&&y>0)
    {
        int gc=__gcd(x,y);
        if(x/gc==Ma&&y/gc==Mb)return 0;
    }
    if(i==n)return inf;
    if(dp[i][x][y]!=-1)return dp[i][x][y];
    int inc=inf,exc=inf;
    int ans=min(c[i]+call(i+1,x+a[i],y+b[i]),call(i+1,x,y));
    return dp[i][x][y]=ans;
}

int main()
{
    cin>>n>>Ma>>Mb;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    int ans=call(0,0,0);
    if(ans>=inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}
