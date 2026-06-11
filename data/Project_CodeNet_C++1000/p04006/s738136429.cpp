#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
int a[N];
int f[N][N];
int n,x;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		f[i][0]=a[i];
		for(int j=1;j<n;j++)
		{
			int cost=i-j;
			if(cost<=0) cost+=n;
			f[i][j]=min(f[i][j-1],a[cost]);
		}
	}
	long long minx=0x3f3f3f3f3f3f3f3f;
	for(int j=0;j<n;j++)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
			sum+=f[i][j];
		sum+=(long long)j*x;
		minx=min(sum,minx);
	}
	printf("%lld\n",minx);
	return 0;
}