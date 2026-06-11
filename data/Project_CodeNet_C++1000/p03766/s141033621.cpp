#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,f[1000005],sum[1000005],ans,Pow;
int main()
{
	long long i;
	scanf("%lld",&n);Pow=(n-1)*(n-1)%mod;
	f[0]=1;f[1]=1;f[2]=1;
	sum[0]=1;sum[1]=2;sum[2]=3;
	for(i=3;i<=n;i++)
	{
		f[i]=(f[i-1]+sum[i-3])%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	for(i=2;i<=n;i++)ans=(ans+(Pow+n-i+1)*f[n-i]%mod)%mod;
	ans=((ans+(n-1)*f[n-1]%mod)%mod+f[n])%mod;
	printf("%lld",ans);
	return 0;
}