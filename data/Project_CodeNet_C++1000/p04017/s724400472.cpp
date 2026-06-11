#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;
typedef long long LL;
LL n,a[MAXN],L,t,lgn;
LL ne[MAXN];
LL f[MAXN][21];
LL divide(LL d)
{
	LL l=1,r=n;
	while(l<=r)
	{
		LL mid=(l+r)>>1;
		if(a[mid]>d) r=mid-1;
		if(a[mid]<=d) l=mid+1;
	}
	return r;
}
int main()
{
	scanf("%lld",&n);
	lgn=log2(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld%lld",&L,&t);
	for(int i=1;i<=n;i++)
	{
		LL x=divide(a[i]+L);
	    f[i][0]=x;
	}
	for(int j=1;j<=lgn;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=t;i++)
	{
		LL times=0;
		LL u,v;
		scanf("%lld%lld",&u,&v);
		if(u>v) swap(u,v);
		for(int j=lgn;j>=0;j--)
		{
			if(f[u][j]<v)
			{
				u=f[u][j];
				times+=pow(2,j);
			}
		}
		times++;
		printf("%lld\n",times);
	}
	return 0;
}
