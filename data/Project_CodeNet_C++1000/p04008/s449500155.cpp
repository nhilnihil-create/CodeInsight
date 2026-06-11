#include<iostream>
#include<cstdio>
#define N (100000+1000)
using namespace std;

struct Edge{int to,next;}edge[N<<1];
int n,k,a[N],head[N],num_edge,ans;

void add(int u,int v)
{
	edge[++num_edge].to=v;
	edge[num_edge].next=head[u];
	head[u]=num_edge;
}

int Dfs(int x)
{
	int maxn=0;
	for (int i=head[x]; i; i=edge[i].next)
		maxn=max(maxn,Dfs(edge[i].to)+1);
	if (maxn==k-1 && x!=1 && a[x]!=1){maxn=-1; ans++;}
	return maxn;
}

int main()
{
	scanf("%d%d%d",&n,&k,&a[1]);
	for (int i=2; i<=n; ++i)
		scanf("%d",&a[i]),add(a[i],i);
	Dfs(1);
	printf("%d",ans+(a[1]!=1));
}