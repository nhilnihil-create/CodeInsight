#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=100005;
int n;
int a[N];
int sum[N];
int m;
LL k;
int bel[N];
int x[N];
int f[N],tmp[N];
void Pow (LL x)
{
	if (x==1)	{for (int u=1;u<=n;u++) f[u]=bel[u];return ;}
	Pow(x>>1);
	for (int u=1;u<=n;u++) tmp[u]=f[f[u]];
	for (int u=1;u<=n;u++) f[u]=tmp[u];
	if (x&1)
	{
		for (int u=1;u<=n;u++) tmp[u]=bel[f[u]];
		for (int u=1;u<=n;u++) f[u]=tmp[u];
	}
}
int ans[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++) sum[u]=a[u]-a[u-1];
	//printf("YES\n");
	scanf("%d%lld",&m,&k);
	for (int u=1;u<=n;u++) bel[u]=u;
	for (int u=1;u<=m;u++) 	{int x;scanf("%d",&x);swap(bel[x],bel[x+1]);}
	//printf("NO\n");
	Pow(k);	
	/*for (int u=1;u<=n;u++) printf("%d ",f[u]);
	printf("\n");*/
	for (int u=1;u<=n;u++) ans[u]=sum[f[u]];
	//for (int u=1;u<=n;u++) printf("%d ",ans[u]);
	LL sum=0;
	for (int u=1;u<=n;u++)
	{
		sum=sum+ans[u];
		printf("%lld.0\n",sum);
	}
	return 0;
}