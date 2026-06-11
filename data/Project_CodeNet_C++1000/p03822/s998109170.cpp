#include<cstdio>
#include<map>
#include<algorithm>
#define maxn 100005
using namespace std;
typedef map<int,int>::iterator miter;
int n,t[maxn];
struct node { int v; node *nxt; } edge[maxn*2],*head[maxn],*ncnt;
void addedge(int u,int v)
{
	ncnt++;
	ncnt->v=v,ncnt->nxt=head[u];
	head[u]=ncnt;
}
void dfs(int u,int fa)
{
	map<int,int> cnt;
	for(node *p=head[u];p;p=p->nxt)
	{
		int v=p->v;
		if(v==fa) continue;
		dfs(v,u);
		cnt[t[v]]++;
	}
	miter it;
	for(it=cnt.begin();it!=cnt.end();it++)
		if(it->second>1) cnt[it->first+1]+=it->second-1;
	if(it!=cnt.begin()) { it--; t[u]=it->first+1; }
}
int main()
{
	ncnt=&edge[0];
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		addedge(i,x); addedge(x,i);
	}
	dfs(1,0);
	printf("%d\n",t[1]);
}