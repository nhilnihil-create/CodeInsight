#include <algorithm>
#include <cstdio>
#include <vector>
#define pb push_back
std::vector<int> son[100005];
int arr[100005], ans, n, k;
inline int dfs(int u)
{
	int res = 1;
	for (int v : son[u])
		res = std::max(res, dfs(v) + 1);
	if (res == k && arr[u])
	{
		ans++;
		return 0;
	}
	return res;
}
int main()
{
	// freopen("AGC004-D.in", "r", stdin);
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
			son[--arr[i]].pb(i);
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
