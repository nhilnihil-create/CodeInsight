#include <cstring>
#include <cstdio>
int lst[100005], to[200005], pre[200005], tot;
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u];
	lst[u] = tot++;
}
int dfs(int u, int fa = -1)
{
	int res = 0;
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] != fa)
			res ^= dfs(to[i], u) + 1;
	}
	return res;
}
int main()
{
	// freopen("AGC017-D.in", "r", stdin);
	memset(lst, -1, sizeof(lst));
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v);
		add_edge(--u, --v);
		add_edge(v, u);
	}
	puts(dfs(0) ? "Alice" : "Bob");
	return 0;
}
