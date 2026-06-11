#include <cstdio>
const int mod=1e9+7;
long long f[4000010],inv[4000010],dp[2010][2010];
int n,K;
int ADD(int x)
{
	return (x>=mod)?x-mod:x;
}
long long calc(long long a,long long b,long long mod)
{
	long long ans=1,t=a;
	for (;b;b>>=1)
	{
		if (b&1) ans=ans*t%mod;
		t=t*t%mod;
	}
	return ans;
}
long long C(int n,int m)
{
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	scanf("%d%d",&n,&K);
	if (K==1)
	{
		printf("1\n");
		return 0;
	}
	f[0]=1;
	for (int i=1;i<=n*K;i++) f[i]=f[i-1]*i%mod;
	inv[n*K]=calc(f[n*K],mod-2,mod);
	inv[0]=1;
	for (int i=n*K-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
	dp[0][0]=1;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++)
		{
			if (i!=0) dp[i][j]=dp[i-1][j];
			if (j!=0) dp[i][j]=ADD(dp[i][j]+dp[i][j-1]*C(n*K-i-(j-1)*(K-1)-1,K-2)%mod);
		}
	printf("%lld\n",dp[n][n]*f[n]%mod);
	return 0;
}