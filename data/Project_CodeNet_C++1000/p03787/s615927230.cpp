#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,dep[N];
vector<int> e[N];
bool vis[N],test;
void dfs(int x){
	vis[x]=1;
	for (int i=0;i<e[x].size();i++){
		int v=e[x][i];
		if (vis[v]){
			if (dep[x]==dep[v]) test=0;
			continue;
		}
		dep[v]=dep[x]^1;
		dfs(v);
	}
}
int points,bipartites,graphs;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1;i<=n;i++)
	if (!vis[i]){
		test=1;dfs(i);
		if (!test) graphs++;else
		if (e[i].size()) bipartites++;else
		points++;
	}
	long long ans=0;
	ans+=1ll*points*points+2ll*points*(n-points);
	ans+=1ll*graphs*graphs+2ll*graphs*bipartites;
	ans+=2ll*bipartites*bipartites;
	printf("%lld\n",ans);
	return 0;
}