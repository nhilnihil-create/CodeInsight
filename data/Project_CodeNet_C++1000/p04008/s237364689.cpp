#include <algorithm>
#include <cstdio>
#include <vector>
int ans, arr[100005], k;
std::vector<int> son[100005];
int dfs(int u)
{
	int dep = 1;
	for (int v : son[u])
		dep = std::max(dep, dfs(v) + 1);
	if (dep == k)
	{
		ans += !!arr[u];
		dep = 0;
	}
	return dep;
}
int main()
{
	// freopen("AGC004-D.in", "r", stdin);
	int n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		if (!i)
		{
			ans += arr[i] != 1;
			arr[i] = 0;
		}
		else
			son[--arr[i]].push_back(i);
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
