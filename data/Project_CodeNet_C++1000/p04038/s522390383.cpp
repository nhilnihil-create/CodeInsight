#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll n,m,f[2005][2005];
ll fact[4000005],inv[4000005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
ll C(ll n,ll m)
{
	return fact[n]*inv[n-m]%MOD*inv[m]%MOD;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	fact[0]=1;
	for(int i=1;i<=4000000;i++)fact[i]=fact[i-1]*i%MOD;
	inv[4000000]=quick_pow(fact[4000000],MOD-2);
	for(int i=3999999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	if(m==1)
	{
		printf("1\n");
		return 0;
	}
	f[n][n]=1;
	for(int i=n;i>=0;i--)
	for(int j=n;j>=i;j--)
	{
		f[i][j]%=MOD;
		if(i)f[i-1][j]+=f[i][j];
		if(i!=j)f[i][j-1]+=f[i][j]*C(i+j*(m-1)-1,m-2)%MOD;
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=n;j++)
//		  printf("%lld ",f[i][j]);
//		printf("\n");
//	}
	printf("%lld\n",f[0][0]*fact[n]%MOD);
	return 0;
}