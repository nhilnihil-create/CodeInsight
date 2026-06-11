#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL n,k,f[2010][2010];
LL fac[4100010],inv[4100010];
void pre()
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=4100000;i++) fac[i]=fac[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(LL i=2;i<=4100000;i++) inv[i]=inv[i-1]*inv[i]%mod;
}
LL C(LL m,LL n) {return fac[m]*inv[m-n]%mod*inv[n]%mod;}
LL get(LL k,LL n)
{
	return C(k+n,n);
}//k->n+1
int main()
{
	pre();
	scanf("%lld %lld",&n,&k);
	if(k==1) return puts("1"),0;
	f[1][0]=1;
	for(LL i=1;i<=n;i++)
		for(LL j=0;j<=i;j++)
		{
			if(j<i) f[i][j+1]=(f[i][j+1]+f[i][j])%mod;
			if(i<n) (f[i+1][j]+=f[i][j]*get(k-2,i*(k-1)+j))%=mod;
		}
	printf("%lld",f[n][n]*fac[n]%mod);
}