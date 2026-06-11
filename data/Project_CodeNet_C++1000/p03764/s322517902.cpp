#include<cstdio>
#define mod (1000000007)
typedef long long ll;
ll x[110000],y[110000];
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&y[i]);
	ll s1=0,s2=0;
	for (int i=1;i<=n;i++) s1=((2*i-n-1)*x[i]+s1)%mod;
	for (int i=1;i<=m;i++) s2=((2*i-m-1)*y[i]+s2)%mod;
	printf("%lld\n",s1*s2%mod);
	return 0;
}