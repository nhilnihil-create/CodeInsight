#include<cstdio>
#define maxn 100005
#define max(a,b) ((a)>(b)?(a):(b))
struct node { int v; node *nxt; } edge[maxn],*head[maxn],*ncnt;
int n,k,a[maxn],dep[maxn],ans;
void addedge(int u,int v)
{
	ncnt++;
	ncnt->v=v,ncnt->nxt=head[u];
	head[u]=ncnt;
}
void dfs(int u)
{
	for(node *p=head[u];p;p=p->nxt)
	{
		int v=p->v;
		dfs(v);
		dep[u]=max(dep[u],(dep[v]+1)%k);
		if(u!=1&&dep[v]==k-1) ans++;
	}
}
int main()
{
	ncnt=&edge[0];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(a[1]!=1) a[1]=1,ans++;
	for(int i=2;i<=n;i++) addedge(a[i],i);
	dfs(1);
	printf("%d\n",ans);
}