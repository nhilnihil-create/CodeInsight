#include<iostream>
#include<cstdio>
#define N (100009)
using namespace std;

struct Edge{int to,next;}edge[N<<1];
int n,u,v,a[N],Ind[N],flag=true;
int head[N],num_edge;

void add(int u,int v)
{
	edge[++num_edge].to=v;
	edge[num_edge].next=head[u];
	head[u]=num_edge;
}

void Dfs(int x,int fa)
{
	if (!flag) return;
	int maxn=0;
	long long sum=0;
	for (int i=head[x]; i; i=edge[i].next)
		if (edge[i].to!=fa)
		{
			Dfs(edge[i].to,x);
			sum+=a[edge[i].to];
			maxn=max(maxn,a[edge[i].to]);
		}
	if (!maxn) return;
	if (sum<a[x] || sum>2*a[x] || maxn>a[x]) flag=false;
	a[x]=a[x]*2-sum;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for (int i=1; i<=n-1; ++i)
	{
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
		Ind[u]++; Ind[v]++;
	}
	
	if (n==2)
	{
		if (a[1]==a[2]) puts("YES");
		else puts("NO"); 
		return 0;
	}
	
	int root=1;
	while (Ind[root]<=1) root++;
	Dfs(root,0);
	if (a[root]!=0) flag=false;
	if (flag) puts("YES");
	else puts("NO");
}