#include<cstdio>
#include<algorithm>
#define LL long long
#define maxn 100005
using namespace std;
int n,a[maxn],deg[maxn],cnt[maxn];
bool vis[maxn];
struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;
void addedge(int u,int v)
{
	ncnt++;
	ncnt->v=v,ncnt->nxt=head[u];
	head[u]=ncnt; deg[u]++;
}
void dfs(int u,int fa)
{
	if(deg[u]==1) { cnt[u]=a[u]; return; }
	for(node *p=head[u];p;p=p->nxt)
	{
		int v=p->v;
		if(v==fa) continue;
		dfs(v,u);
		cnt[u]+=2*a[v]-cnt[v];
		if(2*a[v]-cnt[v]>a[v]||2*a[v]-cnt[v]>a[u]||cnt[u]>2*a[u]) { printf("NO\n"); exit(0); }
	}
}
int main()
{
	ncnt=&edge[0];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==2) { printf("%s\n",a[1]==a[2]?"YES":"NO"); return 0; }
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(deg[i]!=1)
		{
			dfs(i,0); 
			if(cnt[i]!=2*a[i]) { printf("NO\n"); return 0; }
			break;
		}
	printf("YES\n");
}
