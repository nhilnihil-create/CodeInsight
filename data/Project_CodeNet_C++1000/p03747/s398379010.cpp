#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
void umin(ll& a,ll t){if(t<a)a=t;}
const ll INF=1ll<<58;
#define MAXN 200011
ll a[MAXN],w[MAXN];
int main()
{
	ll n=read(),l=read(),t=read(),rk=0;
	for(ll i=0;i<n;++i)
	{
		ll x=read(),dir=read();
		if(dir==1)
		{
			x+=t;
			rk=(rk+x/l)%n;
			a[i]=x%l;
		}
		else
		{
			x-=t;
			rk=(rk-(-x+l-1)/l)%n;
			a[i]=(x%l+l)%l;
		}
	}
	rk=(rk+n)%n;
	std::sort(a,a+n);
	for(ll i=rk;i<n;++i)printf("%lld\n",a[i]);
	for(ll i=0;i<rk;++i)printf("%lld\n",a[i]);
	return 0;
}