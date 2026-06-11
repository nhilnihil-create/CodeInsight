#include <cstdio>
#include <cstring>
int n,k,dp[2001][2001],fac[4000001],ifac[4000001];const int p=1e9+7;
inline int qpow(int bs,int ex){int ans=1;while(ex){if(ex&1)ans=1ll*ans*bs%p;bs=1ll*bs*bs%p;ex>>=1;}return ans;}
inline int binom(int n,int m){return 1ll*fac[n]*ifac[m]%p*ifac[n-m]%p;}
int main()
{
	scanf("%d%d",&n,&k);if(k==1){putchar(49);putchar(10);return 0;}
	fac[0]=1;for(int i=1;i<=n*k;++i)fac[i]=1ll*fac[i-1]*i%p;ifac[n*k]=qpow(fac[n*k],p-2);for(int i=n*k-1;~i;--i)ifac[i]=1ll*ifac[i+1]*(i+1)%p;
	for(int i=0;i<=n;++i)dp[i][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			(dp[i][j]+=dp[i-1][j])%=p;
			(dp[i][j]+=1ll*dp[i][j-1]*(n-j+1)%p*binom(n*k-i-1-(j-1)*(k-1),k-2)%p)%=p;
		}
	}
	printf("%d\n",dp[n][n]);return 0;
}