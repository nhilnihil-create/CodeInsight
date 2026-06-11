#include <bits/stdc++.h>
using namespace std;
int x[100005],a[100005],d[100005],inv[100005],p[100005],tmp[100005],ans[100005],fd[100005];
int main()
{
	int n,m;
	long long k;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		d[i]=x[i]-x[i-1];
		inv[i]=i;
		ans[i]=i;
	}
	scanf("%d%lld",&m,&k);
	for (int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		swap(inv[a[i]],inv[a[i]+1]);
	}
	for (int i=1;i<=n;i++)
	p[inv[i]]=i;
	while (k)
	{
		if (k%2)
		{
			for (int i=1;i<=n;i++)
			ans[i]=p[ans[i]];
		}
		for (int i=1;i<=n;i++)
		tmp[i]=p[p[i]];
		for (int i=1;i<=n;i++)
		p[i]=tmp[i];
		k/=2;
	}
	for (int i=1;i<=n;i++)
	fd[ans[i]]=d[i];
	long long sum=0;
	for (int i=1;i<=n;i++)
	{
		sum+=fd[i];
		printf("%lld\n",sum);
	}
}