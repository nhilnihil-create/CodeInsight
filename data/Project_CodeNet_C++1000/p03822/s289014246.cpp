#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define MAXN 100010
int a[MAXN],dep[MAXN],n;
int Adj[MAXN],V[MAXN],nxt[MAXN],c;
void AddEdge(int u,int v)
{
	c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;
}
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int u)
{
	int l=0;
	for(int i=Adj[u];i;i=nxt[i])
		dfs(V[i]);
	for(int i=Adj[u];i;i=nxt[i])
		a[l++]=dep[V[i]];
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++)
		dep[u]=max(dep[u],a[i]+i+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		AddEdge(a[i],i);
	}
	dfs(1);
	printf("%d\n",dep[1]);
}