#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MaxN = 100003;
int n,a[MaxN];
LL sum[MaxN],asum[MaxN],dp[MaxN];
int main() {
    scanf("%d%d",&n,a+1);
    for (int i=2;i<=n;++i) {
        char ch;
        scanf(" %c %d",&ch,a+i);
        if (ch=='-') a[i]*=-1;
    }
    for (int i=n,j=0;i>=1;--i) {
        sum[i]=sum[i+1]+a[i];
        asum[i]=asum[i+1]+abs(a[i]);
        dp[i]=0x8000'0000'0000'0000LL;
        if (a[i]<0) {
            if (j) dp[i]=-sum[i+1]+sum[j]+asum[j]+a[i];
            j=i;
        }
        dp[i]=max(dp[i],dp[i+1]+a[i]);
    }
    printf("%lld\n",dp[1]);
    return 0;
}