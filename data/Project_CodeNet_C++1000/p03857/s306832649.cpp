#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define LL long long
#define MAXN 200010
map<LL,int>G;
LL col[MAXN];
int vis[MAXN],n,a,b;
int Adj[MAXN],V[MAXN],nxt[MAXN],c;
void AddEdge(int u,int v)
{
	c++;V[c]=v,nxt[c]=Adj[u];
	Adj[u]=c;
}
void dfs1(int u)
{
	vis[u]=1;
	col[u]=col[0];
	for(int i=Adj[u];i;i=nxt[i])
		if(!vis[V[i]])
			dfs1(V[i]);
}
void dfs2(int u)
{
	vis[u]=0;
	col[u]=(col[u]<<20)+col[0];
	G[col[u]]++;
	for(int i=Adj[u];i;i=nxt[i])
		if(vis[V[i]])
			dfs2(V[i]);
}
int main()
{
	int u,v;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
		AddEdge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			col[0]++;
			dfs1(i);
		}
	memset(Adj,0,sizeof Adj);
	col[0]=0,c=0;
	for(int i=0;i<b;i++)
	{
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
		AddEdge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(vis[i])
		{
			col[0]++;
			dfs2(i);
		}
	for(int i=1;i<=n;i++)
		printf("%d ",G[col[i]]);
}