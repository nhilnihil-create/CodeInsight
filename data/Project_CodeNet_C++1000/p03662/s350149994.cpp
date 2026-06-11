#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> E[maxn], path;
int siz[maxn], fa[maxn]; 
bool dfs(int x)
{
	siz[x] = 1;
	for(auto v : E[x])
		if(v != fa[x])
		{
			fa[v] = x;
			dfs(v);
			siz[x] += siz[v];
		} 
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1);
	int u = n;
	while(u)
	{
		path.push_back(u);
		u = fa[u];
	}
	reverse(path.begin(), path.end());
	int s = siz[path[(path.size() + 1) >> 1]];
	if(n - s <= s) puts("Snuke");
	else puts("Fennec");
	return 0;
}