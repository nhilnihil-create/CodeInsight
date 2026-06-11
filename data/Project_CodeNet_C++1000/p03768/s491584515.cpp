#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
const int maxn = 1e5+10;
int n,m,q;
vector <int> vec[maxn];
int ans[maxn];
int dp[maxn][11];
int x[maxn],y[maxn],z[maxn];
int vis[maxn];
void dfs(int u,int d,int c)
{
	if(!ans[u]) ans[u]=z[c];
	if(dp[u][d]) return ;
	dp[u][d]=1;
	if(d==0) return ;
	for(auto v:vec[u]) dfs(v,d-1,c);
}

int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	while(m--)
	{
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for(int i=q;i;i--) dfs(x[i],y[i],i);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
