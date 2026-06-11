#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int a[100010],k,n,dis[100010],ans,in[100010],cnt,f[100010];
struct edge{int to,lt;}e[100010];bool vis[100010];

void addedge(int x,int y)
{
	e[++cnt].to=y;e[cnt].lt=in[x];in[x]=cnt;
}

void dfs(int x,int fa)
{
	vis[x]=1;f[x]=1;
	for(int i=in[x];i;i=e[i].lt)
	{
		int v=e[i].to;
		if(v==fa||vis[v])	continue;
		dis[v] = dis[x]+1;
		dfs(v,x);f[x]=max(f[x],f[v]+1);
	}
	if(dis[x]>1&&f[x]>=k){f[x]=0;ans++;}
}

int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i!=1)	addedge(a[i],i);
	}
	dfs(1,1);
	if(a[1]!=1)	ans++;
	printf("%d\n",ans);
	return 0;
}