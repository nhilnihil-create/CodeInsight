#include <bits/stdc++.h>
using namespace std;

#define MAXN 2010
#define mod 1000000007

int n,k,fac[MAXN*MAXN],inv[MAXN*MAXN],f[MAXN][MAXN];

int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=(long long)res*a%mod;
		a=(long long)a*a%mod;
		b>>=1;
	}
	return res;
}

int c(int n,int m)
{
	if(n<0 || n<m)return 0;
	return (long long)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		puts("1");
		return 0;
	}
	fac[0]=inv[0]=1;
	for(int i=1;i<=n*k;++i)fac[i]=(long long)fac[i-1]*i%mod;
	inv[n*k]=qpow(fac[n*k],mod-2);
	for(int i=n*k-1;i>=1;--i)inv[i]=(long long)inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=i;j>=0;--j)
		{
			f[i+1][j+1]=(f[i+1][j+1]+(long long)f[i][j]*c(i*k-j+k-2,k-2)%mod)%mod;
			if(j)f[i][j-1]=(f[i][j-1]+f[i][j])%mod;
		}
	printf("%lld\n",(long long)f[n][0]*fac[n]%mod);
}