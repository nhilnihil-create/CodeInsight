#include<cstdio>
#define maxn 100005
#define maxm 200005
int n,m,ia,pa,qa;
bool f,val[maxn],vis[maxn];
struct node { int v; node *nxt; } edge[maxm*2],*head[maxn],*ncnt;
void addedge(int u,int v)
{
	ncnt++;
	ncnt->v=v,ncnt->nxt=head[u];
	head[u]=ncnt;
}
void dfs(int u)
{
	vis[u]=true;
	for(node *p=head[u];p;p=p->nxt)
	{
		int v=p->v;
		if(!vis[v]) { val[v]=val[u]^1; dfs(v); }
		else if(val[u]==val[v]) f=true;
	}
}
int main()
{
	ncnt=&edge[0];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) 
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!head[i]) ia++;
		else if(!vis[i])
		{
			f=false;
			dfs(i);
			if(f) pa++;
			else qa++;
		}
	}
	printf("%lld\n",1ll*ia*ia+2ll*ia*(n-ia)+1ll*pa*pa+2ll*qa*qa+2ll*pa*qa);
}
