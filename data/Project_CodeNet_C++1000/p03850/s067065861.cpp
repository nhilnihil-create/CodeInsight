#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
ll ty[MAXN],a[MAXN],dp[MAXN][3];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i>1)
        {
            char op[5];
            scanf("%s",op);
            ty[i]=(*op=='-');
        }
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<3;j++)
            dp[i][j]=-INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            ll now=(ty[i] ? -1 : 1)*a[i];
            if(j<3 && ty[i-1])
                dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+((j+1)&1 ? -1 : 1)*now);
            dp[i][j]=max(dp[i][j],dp[i-1][j]+(j&1 ? -1 : 1)*now);
        }
        for(int j=1;j>=0;j--)
            dp[i][j]=max(dp[i][j],dp[i][j+1]);
    }
    return 0*printf("%lld\n",dp[n][0]);
}