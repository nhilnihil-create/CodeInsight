#include<cstdio>
#define maxn 100005
int n;
struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;
void addedge(int u,int v)
{
	ncnt++;
	ncnt->v=v,ncnt->nxt=head[u];
	head[u]=ncnt;
}
int dfs(int u,int fa)
{
	int res=0;
	for(node *p=head[u];p;p=p->nxt)
	{
		int v=p->v;
		if(v!=fa) res^=dfs(v,u)+1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	ncnt=&edge[0];
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	printf("%s\n",dfs(1,0)?"Alice":"Bob");
}