#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,b[N],fl[N];long double a[N];long long k;
int u[N];
void work(int a[],int b[])
{
	int ans[N];
	for (int i=1;i<n;i++)
		ans[i]=a[b[i]];
	for (int i=1;i<n;i++)
		a[i]=ans[i];
}
void work(int u[],long long k)
{
	int ans[N];
	for (int i=1;i<n;i++)
		ans[i]=i;
	for (;k;k>>=1)
	{
		if (k&1) work(ans,u);
		work(u,u);
	}
	for (int i=1;i<n;i++)
		u[i]=ans[i];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%Lf",&a[i]);
	
	scanf("%d%lld",&m,&k);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<n;i++)
		u[i]=i;
	for (int i=1;i<=m;i++)
		swap(u[b[i]-1],u[b[i]]);
	work(u,k);
	double now=a[1];
	for (int i=1;i<=n;i++)
	{
		printf("%.9f\n",now);
		now+=a[u[i]+1]-a[u[i]];
	}
}