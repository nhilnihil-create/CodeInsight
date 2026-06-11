#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int rt, K, n, cnt, typ;
vector<int> linker[2005];

void dfs(int x, int fa, int ndep)
{
	if (ndep > ((K - typ) >> 1)) ++ cnt;
	for (int cur : linker[x])
		if (cur != fa) dfs(cur, x, ndep + 1);
}

int main()
{
	scanf("%d %d", &n, &K);
	for (int i = 1; i < n; i ++)
	{
		int u, v; scanf("%d %d", &u, &v);
		linker[u].push_back(v), linker[v].push_back(u);
	}
	int ans = n; typ = 0;
	for (rt = 1; rt <= n; rt ++)
	{
		cnt = 0, dfs(rt, 0, 0);
		ans = min(ans, cnt);
	}
	typ = 1;
	for (rt = 1; rt <= n; rt ++)
	{
		for (auto rt2 : linker[rt])
		{
			cnt = 0;
			dfs(rt, rt2, 0), dfs(rt2, rt, 0);
			ans = min(ans, cnt);
		}
	}
	cout << ans << endl;
	return 0;
}