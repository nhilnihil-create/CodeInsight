#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
int Adj[MAXN],V[MAXN],nxt[MAXN],c;
void AddEdge(int u,int v)
{
	c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;
}
int fa[MAXN],dep[MAXN],k,n,ans;
void dfs(int u)
{
	dep[u]=1;
	for(int i=Adj[u];i;i=nxt[i])
	{
		dfs(V[i]);
		dep[u]=max(dep[u],dep[V[i]]+1);
	}
	if(fa[u]!=1&&dep[u]==k)
	{
		ans++;
		dep[u]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%d",&fa[1]);
	if(fa[1]!=1) ans++,fa[1]=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		AddEdge(fa[i],i);
	}
	dfs(1);
	printf("%d\n",ans);
}