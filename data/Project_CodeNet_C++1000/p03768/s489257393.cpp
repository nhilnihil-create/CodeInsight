#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,m,q,vt[Maxn],d[Maxn],c[Maxn],i,dp[Maxn],col[Maxn];
vector <int> g[Maxn];
void dfs(int v,int d,int c)
{
	if (!col[v]) col[v]=c;
	if (dp[v]>=d || d==0) return;
	dp[v]=d;for (int i=0;i<g[v].size();++i)
		dfs(g[v][i],d-1,c);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%d",&q);
	for (i=0;i<q;i++) scanf("%d%d%d",vt+i,d+i,c+i);
	for (i=q-1;i>=0;i--) dfs(vt[i],d[i],c[i]);
	for (i=1;i<=n;i++) printf("%d\n",col[i]);
	return 0;
}