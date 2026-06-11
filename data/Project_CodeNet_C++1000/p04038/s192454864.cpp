#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
LL dp[2005][2005],n,k,fac[4000005],inv[4000005];
LL QuickPow(LL x,LL p)
{
	LL base=x,ans=1;
	while(p)
	{
		if(p&1)	ans*=base,ans%=MOD;
		p>>=1;
		base*=base;
		base%=MOD;
	}
	return ans;
}
LL C(LL n,LL m){return fac[m]*inv[n]%MOD*inv[m-n]%MOD;}
int main(){
	fac[0]=1;
	scanf("%lld %lld",&n,&k);
	if(k==1)	return puts("1")&0;
	for(LL i=1;i<=n*k;++i)	fac[i]=fac[i-1]*i%MOD;
	inv[n*k]=QuickPow(fac[n*k],MOD-2);
	for(LL i=n*k-1;~i;--i)	inv[i]=inv[i+1]*(i+1)%MOD;
	for(LL i=0;i<=n;++i)	dp[i][0]=1;
	for(LL i=1;i<=n;++i)
	{
		for(LL j=1;j<=i;++j)
		{
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]*(n-j+1)%MOD*C(k-2,n*k-i-(j-1)*(k-1)-1)%MOD)%MOD;
		}
	}
	printf("%lld\n",dp[n][n]);
	return 0;
}