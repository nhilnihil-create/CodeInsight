#include<bits/stdc++.h>
using namespace std;
int a[100010],d[100010],t[100010];
long long x[100010],ans[100010];
int main()
{
	int n,m,tt;
	long long k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",x+i),d[i]=a[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&tt);
		swap(d[tt],d[tt+1]);
	}
	while(k)
	{
		if(k&1)
		{
			for(int i=1;i<=n;i++)t[i]=a[d[i]];
			for(int i=1;i<=n;i++)a[i]=t[i];
		}
		for(int i=1;i<=n;i++)t[i]=d[d[i]];
		for(int i=1;i<=n;i++)d[i]=t[i];
		k>>=1;
	}
	for(int i=1;i<=n;i++)ans[i]=x[a[i]]-x[a[i]-1];
	for(int i=1;i<=n;i++)printf("%lld.0\n",ans[i]+=ans[i-1]);
	puts("");
	return 0;
}