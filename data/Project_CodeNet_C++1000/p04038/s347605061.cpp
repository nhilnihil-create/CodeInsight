#include<cstdio>
#define neko 2010
#define f(i,a,b) for(register int i=(a);i<=(b);i=-(~(i)))
#define rf(i,a,b) for(register int i=(a);i>=(b);i=~(-(i)))
typedef long long ll;
ll dp[neko][neko],fac[neko*neko],ifac[neko*neko];
const ll mod=1e9+7;
int n,k;
ll ADD(ll x,ll y){return (x+=y)>=mod?x-mod:x;}
ll spow(ll m,ll n)
{
	ll b=1;
	for(;n;n>>=1,m=m*m%mod)if(n&1)b=b*m%mod;
	return b;
}
ll C(ll m,ll n){if(m<n)return 1;if(!n)return 1;return fac[m]*ifac[n]%mod*ifac[m-n]%mod;}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)return printf("1\n"),0;
	fac[0]=ifac[0]=1;
	f(i,1,4000005)fac[i]=fac[i-1]*i%mod;
	ifac[4000005]=spow(fac[4000005],mod-2);
	rf(i,4000004,1)ifac[i]=ifac[i+1]*(i+1)%mod;
	dp[0][0]=1;
	f(i,0,n)
	 f(j,i,n)
	 {
		if(i)dp[i][j]=ADD(dp[i-1][j],dp[i][j]);
		if(j)dp[i][j]=ADD(dp[i][j],dp[i][j-1]*C(i+(j-1)*(k-1)+k-2,k-2)%mod);
	 }return printf("%lld\n",(dp[n][n]*fac[n]%mod+mod)%mod),0;
}