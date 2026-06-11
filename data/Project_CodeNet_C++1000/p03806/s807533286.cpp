#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=410;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,A,B,dp[N/10+1][N][N];
struct Node { int a,b,c; }q[N];
signed main()
{
    n=read(), A=read(), B=read();
    for(ri int i=0;i<n;i++) q[i].a=read(), q[i].b=read(), q[i].c=read();
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(ri int i=0;i<n;i++)
    for(ri int j=0;j<=400;j++)
    for(ri int k=0;k<=400;k++)
    {
        if(dp[i][j][k]==dp[N/10][N-1][N-1]) continue;
        dp[i+1][j][k]=min(dp[i][j][k],dp[i+1][j][k]);
        dp[i+1][j+q[i].a][k+q[i].b]=min(dp[i+1][j+q[i].a][k+q[i].b],dp[i][j][k]+q[i].c);
    }
    int res=8e18;
    for(ri int i=1;i<=400;i++)
    for(ri int j=1;j<=400;j++) if(i*B==j*A) res=min(res,dp[n][i][j]);
    
    if(res>=dp[N/10][N-1][N-1]) puts("-1");
    else printf("%lld\n",res);
    return 0;
}