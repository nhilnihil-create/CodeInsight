#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 1000005;
const int mod = 1e9+7;

LL dp[maxn],s[maxn],ans;int n;
int main()
{
	#ifdef Amberframe
		freopen("arc071f.in","r",stdin);
		freopen("arc071f.out","w",stdout);
	#endif
	
	scanf("%d",&n);
	dp[0]=s[0]=1;ans=1;
	for (int i=1;i<=n;i++) {
		dp[i]=((i>=3?s[i-3]:0)+dp[i-1])%mod;
		s[i]=(s[i-1]+dp[i])%mod;
	}
	LL w=(LL)(n-1)*(n-1)%mod;
	for (int i=1;i<=n;i++) {
		if (i>=4) ans=(ans+s[i-4])%mod;
		if (i==n) {
			ans=(ans+dp[i-1]*(n-1))%mod;
		}
		else if (i==n-1) {
			ans=(ans+dp[i-1]*(n-1))%mod;
			ans=(ans+dp[i-1]*w)%mod;
		}
		else {
			ans=(ans+dp[i-1]*(LL)(i+1))%mod;
			ans=(ans+dp[i-1]*w)%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}