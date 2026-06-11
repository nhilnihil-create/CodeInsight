#include <stdio.h>
#include <algorithm>
using namespace std;
bool minus[100001];
int a[100001];
long long dp[100001][3];
const long long NINF=-1000000000000000000;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        if (i>1)
        {
            char x;
            scanf(" %c",&x);
            minus[i]=x=='-';
        }
        scanf("%d",&a[i]);
    }
    dp[0][1]=dp[0][2]=-1e18;
    for (int i=1;i<=n;++i)
    {
        if (minus[i])
        {
            dp[i][0]=dp[i][1]=max(dp[i-1][0]-a[i],max(dp[i-1][1]==NINF?NINF:dp[i-1][1]+a[i],
                dp[i-1][2]==NINF?NINF:dp[i-1][2]-a[i]));
            dp[i][2]=max(dp[i-1][1]==NINF?NINF:dp[i-1][1]+a[i],dp[i-1][2]==NINF?NINF:dp[i-1][2]-a[i]);
        }
        else
        {
            dp[i][0]=max(dp[i-1][0]+a[i],max(dp[i-1][1]==NINF?NINF:dp[i-1][1]-a[i],
                dp[i-1][2]==NINF?NINF:dp[i-1][2]+a[i]));
            dp[i][1]=max(dp[i-1][1]==NINF?NINF:dp[i-1][1]-a[i],dp[i-1][2]==NINF?NINF:dp[i-1][2]+a[i]);
            dp[i][2]=dp[i-1][2]==NINF?NINF:dp[i-1][2]+a[i];
        }
    }
    printf("%lld\n",dp[n][0]);
    return 0;
}
