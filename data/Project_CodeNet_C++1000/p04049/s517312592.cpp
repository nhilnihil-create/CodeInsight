#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,k,h[100005],t,f[2005][2005],tmp[2005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
	memset(tmp,0,sizeof(tmp));
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		for(int j=0;j<k;j++)
		{
			tmp[j+1]+=f[v][j];
			if(j==k-1) f[u][j+1]=max(f[u][j+1],f[v][j]);
			else if(2*(j+1)>k) f[u][j+1]=max(f[u][j+1],f[v][j]-f[v][k-j-2]);
		}
	}
	for(int j=0;j<=k;j++)
	{
		if(2*j<=k) f[u][j]=tmp[j]+1;
		else f[u][j]=f[u][j]+tmp[k-j]+1;
	}
	for(int j=1;j<=k;j++)
		f[u][j]=max(f[u][j],f[u][j-1]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][k]);
	printf("%d",n-ans);
	return 0;
}