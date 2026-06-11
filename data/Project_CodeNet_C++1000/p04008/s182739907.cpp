#include <bits/stdc++.h>
using namespace std;

const int MaxN(100003);
int fa[MaxN], n, K, ans;
vector<int> G[MaxN];

int dfs(int u)
{
	int d = 0;
	for(auto v : G[u])
		d = max(d, dfs(v));
	if(d == K - 1)
		ans += (fa[u] != 1), d = -1;
	return d + 1;
}

int main()
{
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++)
		scanf("%d", &fa[i]);
	ans = (fa[1] != 1), fa[1] = 1;
	for(int i = 2; i <= n; i++)
		G[fa[i]].push_back(i);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
