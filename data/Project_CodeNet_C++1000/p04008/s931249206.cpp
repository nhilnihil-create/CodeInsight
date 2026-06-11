#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100005
using namespace std;
int n,k,a[maxn],ans;
struct node
{
	int v,nxt;
}G[maxn];
int adj[maxn],num_Edge=0;
void add(int x,int y)
{
	G[++num_Edge].v=y;
	G[num_Edge].nxt=adj[x];
	adj[x]=num_Edge;
}
int f[maxn],g[maxn];
void dfs(int x)
{
	//printf("%d",x);
	f[x]=g[x]=0;
	for(int i=adj[x];i!=-1;i=G[i].nxt)
	{
		int V=G[i].v;
		dfs(V);
		f[x]+=f[V];
		if(g[V]+1>=k) f[x]++;
		else g[x]=max(g[x],g[V]+1);
	}
}
int main()
{
	memset(adj,-1,sizeof(adj));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1) add(a[i],i); 
	}
	for(int i=adj[1];i!=-1;i=G[i].nxt)
	{
		dfs(G[i].v);
		ans+=f[G[i].v];
	}
	if(a[1]!=1) ans++;
	printf("%d",ans);
	return 0;
}