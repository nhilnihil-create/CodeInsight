#include<bits/stdc++.h>
#define maxn 1000005
#define mod 1000000007
using namespace std;
typedef long long LL;
LL read()
{
    char c=getchar();LL f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
LL n,ans;
LL dp[maxn],sum[maxn];
int main()
{
	n=read();
	dp[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=3) dp[i]=(dp[i]+sum[i-3])%mod;
		dp[i]=(dp[i]+dp[i-1])%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	for(int i=1;i<n;i++) ans=(ans+dp[i]*(n-1)%mod*(n-1)%mod)%mod;
	for(LL i=1;i<n;i++) ans=(ans+dp[i]*min(i+1,n-1)%mod)%mod;
	ans=(ans+dp[n]*n%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
