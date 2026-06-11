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
int N;
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
int DFS(int u,int fa)
{
	int ret=0;
	for(node *p=Adj[u];p!=NULL;p=p->nxt)
	{
		int v=p->to;
		if(v==fa)
			continue;
		ret^=(DFS(v,u)+1);
	}
	return ret;
}
int main()
{
	scanf("%d",&N);
	int u,v;
	for(int i=1;i<N;i++)
	{
		scanf("%d %d",&u,&v);
		AddEdge(u,v);
	}
	if(DFS(1,-1)==0)
		printf("Bob\n");
	else
		printf("Alice\n");
	return 0;
}