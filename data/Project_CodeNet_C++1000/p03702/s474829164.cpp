#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,h[100005],ans[100005];
bool check(ll x)
{
	for(int i=1;i<=n;i++)
	{
		ll val=h[i];
		val-=x*b;
		if(val>0)
		{
			ans[i]=(val-1)/(a-b)+1;
		}
		else ans[i]=0;
	}
	ll tot=0;
	for(int i=1;i<=n;i++) tot+=ans[i];
	return tot<=x;
}
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
	ll l=1,r=1e9;
	while(r-l>1)
	{
		//printf("l=%lld r=%lld\n",l,r);
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(check(l)) printf("%lld\n",l);
	else printf("%lld\n",r);
	return 0;
}