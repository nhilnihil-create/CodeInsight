#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define maxn 100005
int n,m,q,s[maxn],d[maxn],x[maxn],maxd[maxn],c[maxn],que[maxn],fr,bk;
struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;
void addedge(int u,int v)
{
	ncnt++;
	ncnt->v=v,ncnt->nxt=head[u];
	head[u]=ncnt;
}
void dfs(int u,int d,int x)
{
	if(maxd[u]>=d) return;
	if(!c[u]) c[u]=x;
	if(!d) return;
	maxd[u]=d;
	for(node *p=head[u];p;p=p->nxt) dfs(p->v,d-1,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	ncnt=&edge[0];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	memset(maxd,-1,sizeof(maxd));
	scanf("%d",&q);
	for(int i=1;i<=q;i++) scanf("%d%d%d",&s[i],&d[i],&x[i]);
	for(int i=q;i;i--) dfs(s[i],d[i],x[i]); 
	for(int i=1;i<=n;i++) printf("%d\n",c[i]);
}