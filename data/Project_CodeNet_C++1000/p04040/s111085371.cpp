#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll n,m,a,b;
ll fpow(ll b,ll p,ll mod)
{
	ll ans=1,tmp=b;
	while(p)
	{
		if(p&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		p>>=1;
	}
	return ans%mod;
}
ll inv(ll b,ll mod)
{
	return fpow(b,mod-2,mod)%mod;
}
const int N=200002;
const ll mod=1e9+7;
ll fac[N],ans=0;
ll C(ll n,ll m)
{
	if(n<m)return 0;
	return fac[n]%mod*inv(fac[m],mod)%mod*inv(fac[n-m],mod)%mod;
}
ll Lucas(ll n,ll m)
{
	if(!m)return 1;
	return C(n%mod,m%mod)*Lucas(n/mod,m/mod);
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=200000;i++)fac[i]=fac[i-1]*i%mod;
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	for(ll i=1;i<=n-a&&i<=m-b;i++)
	{
		ll X=n-a-i,Y=b+i-1;
		ans=(ans+Lucas(X+Y,X)%mod*Lucas(m-Y+n-X-2,m-Y-1)%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}