#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e5+5;
int n,m,k,inv,a[N],b[N],cf[N],c[N],xu[N],f[N][65];
int xjh(int x,int y)
{
	for(int i=62;i>=0;i--)
		if(y&((long long)1<<i))x=f[x][i];
	return x;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cf[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++)a[i]=i;
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
		swap(a[b[i]],a[b[i]+1]);
	}
	for(int i=1;i<=n;i++)f[i][0]=a[i];
	for(int i=1;i<=62;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=n;i++)xu[i]=cf[xjh(i,k)];
	double jia=0.0;
	for(int i=1;i<=n;i++)
	{
		jia=jia+(double)xu[i];
		printf("%.1lf\n",jia);
	}
	return 0;
}