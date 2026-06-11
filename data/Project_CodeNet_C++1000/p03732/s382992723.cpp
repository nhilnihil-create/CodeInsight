//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=501;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,S,mi=2e9,F;
struct Node { int w,v; }q[N];
int dp[N][N][N];
signed main()
{
    n=read(), S=read();
    for(ri int i=1;i<=n;i++) q[i].w=read(), q[i].v=read();
    mi=q[1].w;
    for(ri int i=1;i<=n;i++) q[i].w-=mi;
    
    for(ri int i=1;i<=n;i++)
    for(ri int j=0;j<=n;j++)
    for(ri int k=1;k<=n;k++)
    {
        if(j>=q[i].w) dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-q[i].w][k-1]+q[i].v);
        else dp[i][j][k]=dp[i-1][j][k];
    }

    int res=0;
    for(ri int i=0;i<=300;i++)
    for(ri int j=0;j<=n;j++)
    if(j*mi+i<=S) res=max(res,dp[n][i][j]);

    printf("%lld\n",res);
    return 0;
}