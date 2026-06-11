#include <iostream>
#include <cstdio>
#define maxn 2005
using namespace std;
const long long INF=999999999999999;
int n;
long long x;
long long a[maxn],d[maxn][maxn];
long long ans,res;
int main()
{
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		d[i][i-1]=INF;
		for(int j=i;j<=n;j++)
		{
			d[i][j]=min(d[i][j-1],a[j]);
		}
	}
	ans=INF;
	for(int i=0;i<=n;i++)
	{
		res=i*x;
		for(int j=1;j<=i;j++)
		{
			res+=min(d[n-i+j][n],d[1][j]);
			if(res>=INF) break;
		}
		for(int j=i+1;j<=n;j++)
		{
			res+=d[j-i][j];
			if(res>=INF) break;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}