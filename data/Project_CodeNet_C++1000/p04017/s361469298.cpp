#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll n,len,q;
ll num;
ll block;
ll a[100010];
ll b[100010];
ll to[100010];
ll nxt[100010];
ll step[100010];

ll find(ll x)
{
	ll ans=0;
	ll l=x+1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(a[mid]-a[x]<=len)
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}

void build()
{
	for(ll i=1;i<n;i++)
	{
		to[i]=find(i);
	}
	to[n]=n+1;	//这句话一定要加，不然就在下面while的地方死循环 
	block=sqrt(n);
	num=ceil(n/block);
	for(ll i=1;i<=n;i++)
	{
		b[i]=(i-1)/block+1;
	}
	for(ll i=1;i<=n;i++)
	{
		ll p=i,cnt=0;
		while(b[p]==b[i])
		{
			p=to[p];
			cnt++;
		}
		nxt[i]=p;
		step[i]=cnt;
	}
}

ll query(ll x,ll y)
{
	ll res=0;
	while(b[x]<b[y])
	{
		res+=step[x];
		x=nxt[x];
	}
	while(x<y)
	{
		x=to[x];
		res++;
	}
	return res;
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	scanf("%lld%lld",&len,&q);
	build();
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		if(x>y) swap(x,y);
		printf("%lld\n",query(x,y));
	}
	return 0;
}










