#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000
using namespace std;
struct node
{
	int to;
	node *nxt;
}edges[MAXN*2+5];
node *ncnt=&edges[0],*Adj[MAXN+5];
int n,m,q,col[MAXN+5],maxd[MAXN+5];
int V[MAXN+5],D[MAXN+5],C[MAXN+5];
void Init()
{
	memset(maxd,-1,sizeof(maxd));
}
void AddEdge(int u,int v)
{
	node *p=++ncnt;
	p->to=v;
	p->nxt=Adj[u];
	Adj[u]=p;
	
	node *q=++ncnt;
	q->to=u;
	q->nxt=Adj[v];
	Adj[v]=q;
}
void DFS(int u,int d,int c)
{
	if(col[u]==0)
		col[u]=c;
	if(maxd[u]>=d)
		return;
	if(d==0)
		return;
	maxd[u]=d;
	for(node *p=Adj[u];p!=NULL;p=p->nxt)
	{
		int v=p->to;
		DFS(v,d-1,c);
	}
}
int main()
{
//	freopen("splatter.in","r",stdin);
//	freopen("splatter.out","w",stdout);
	Init();
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		AddEdge(u,v);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d %d %d",&V[i],&D[i],&C[i]);
	for(int i=q;i>=1;i--)
		DFS(V[i],D[i],C[i]);
	for(int i=1;i<=n;i++)
		printf("%d\n",col[i]);
	return 0;
}