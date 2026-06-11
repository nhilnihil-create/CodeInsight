#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
const ll MAXN=520233;
ll n,m,sum,w[MAXN+10],a[MAXN+10],f[MAXN+10],ff[MAXN+10];
ll M(ll x){return (x%m+m)%m;}
int main()
{
	scanf("%lld%lld%lld",&n,&m,a+1);--a[1];
	for(ll i=2,ad;i<=n;++i)
	{
		scanf("%lld",a+i);--a[i];
		sum+=M(a[i]-a[i-1]);
		if(a[i-1]==a[i])continue;
		ad=(a[i-1]>a[i])*m;
		++ff[a[i-1]+2];
		--ff[ad+a[i]+1];
		f[ad+a[i]+1]-=(ad+a[i]+1)-(a[i-1]+2);
	}
	for(ll i=1;i<2*m;++i)ff[i]+=ff[i-1];
	for(ll i=1;i<2*m;++i)ff[i]+=ff[i-1];
	for(ll i=1;i<2*m;++i)f[i]+=f[i-1];
	ll mx=0;
	for(ll i=0;i<m;++i)mx=max(mx,f[i]+ff[i]+f[m+i]+ff[m+i]);
	printf("%lld",sum-mx);
	return 0;
}