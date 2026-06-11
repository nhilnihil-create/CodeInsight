#include<iostream>
#include<cstdio>
#define N (5000000+1000)
#define MOD (1000000007)
using namespace std;

long long n,k,fac[N],inv[N],facinv[N],f[2010][2010];

void Init()
{
	fac[0]=inv[1]=facinv[0]=1;
	for (int i=1; i<=5000000; ++i)
	{
		if (i!=1) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		fac[i]=fac[i-1]*i%MOD; 
		facinv[i]=facinv[i-1]*inv[i]%MOD;
	}
}

long long C(long long n,long long m)
{
	if (m>n) return 0;
	return fac[n]*facinv[m]%MOD*facinv[n-m]%MOD;
}

int main()
{
	Init();
	scanf("%lld%lld",&n,&k);
	if (k==1){printf("1"); return 0;}
	f[0][1]=1;
	for (int i=2; i<=n; ++i)
		f[0][i]=f[0][i-1]*C(i*(k-1)-1,k-2)%MOD;
	for (int i=1; i<=n; ++i)
		for (int j=i; j<=n; ++j)
			f[i][j]=(f[i-1][j]+f[i][j-1]*C(i+j*(k-1)-1,k-2)%MOD)%MOD;
	printf("%lld",f[n][n]*fac[n]%MOD);
}
 