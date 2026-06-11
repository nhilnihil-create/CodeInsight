#include<bits/stdc++.h>
#define N (100000+1000)
using namespace std;

long long n,m,k,x,a[N],d[N],p[N],ans[N],tmp[N],sum;

void Qpow()
{
	for (int i=1; i<=n; ++i) ans[i]=i;
	while (k)
	{
		if (k&1)
		{
			for (int i=1; i<=n; ++i) tmp[i]=ans[p[i]];
			for (int i=1; i<=n; ++i) ans[i]=tmp[i];
		}
		for (int i=1; i<=n; ++i) tmp[i]=p[p[i]];
		for (int i=1; i<=n; ++i) p[i]=tmp[i];
		k>>=1;
	}
	for (int i=1; i<=n; ++i) tmp[i]=d[ans[i]];
	for (int i=1; i<=n; ++i) d[i]=tmp[i];
}

int main()
{
	scanf("%lld",&n);
	for (int i=1; i<=n; ++i)
		scanf("%lld",&a[i]),d[i]=a[i]-a[i-1],p[i]=i;
	scanf("%lld%lld",&m,&k);
	for (int i=1; i<=m; ++i)
		scanf("%lld",&x),swap(p[x],p[x+1]);
	Qpow();
	for (int i=1; i<=n; ++i)
		sum+=d[i],printf("%lld\n",sum);
}