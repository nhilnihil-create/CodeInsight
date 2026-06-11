#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=3e5;
const ll p=1e9+7;
ll fac[N+10],ifac[N+10];

ll fpm(ll a,ll b)
{
	ll ret=1;
	for(;b;b>>=1) ret=(b&1)?ret*a%p:ret,a=a*a%p;
	return ret;
}

void init(void)
{
	fac[0]=1;
	for(int i=1;i<=N;++i) fac[i]=fac[i-1]*i%p;
	ifac[N]=fpm(fac[N],p-2);
	for(int i=N;i>=1;--i) ifac[i-1]=ifac[i]*i%p;
}

ll C(ll n,ll m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}

ll f(ll h,ll w){return C(h-1+w-1,h-1);}

void add(ll &a,ll b){a=a+b>=p?a+b-p:a+b;}

int main()
{
	init();
	int h,w,a,b;scanf("%d %d %d %d",&h,&w,&a,&b);
	ll ans=0;
	for(int i=1;i<=h-a;++i) 
		add(ans,f(i,b)*f(h+1-i,w-b)%p);
	printf("%lld\n",ans);
	return 0;
}
