#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int sg[maxn];
vector<int> E[maxn];
void dfs(int x, int fa)
{
	for(auto v : E[x])
		if(v != fa)
		{
			dfs(v, x);
			sg[x] ^= (sg[v] + 1);
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
	dfs(1, 0);
	puts(sg[1] ? "Alice" : "Bob");
	return 0;
}