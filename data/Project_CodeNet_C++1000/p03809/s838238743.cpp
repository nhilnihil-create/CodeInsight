#include <cstdio>
#include <algorithm>
int N, E, head[100001], next[199999], to[199999], root, q[100001], fa[100001];
long long a[100001], b[100001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", a + i);
	if (N == 2)
	{
		puts(a[1] == a[2] ? "YES" : "NO");
		return 0;
	}
	for (int i = 1, u, v; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		next[++E] = head[u], to[E] = v, head[u] = E;
		next[++E] = head[v], to[E] = u, head[v] = E;
	}
	do root++; while (!next[head[root]]);
	do
	{
		int H = 0, T = 1, u;
		q[1] = root;
		while (H < T)
			for (int e = head[u = q[++H]]; e; e = next[e])
				if (to[e] != fa[u])
					fa[q[++T] = to[e]] = u;
	}
	while (0);
	for (int i = 1; i <= N; i++)
		for (int e = head[q[i]]; e; e = next[e])
			if (to[e] != fa[q[i]])
				a[q[i]] -= a[to[e]];
	for (int i = 1; i <= N; i++)
		if (!next[head[i]])
		{
			b[i] = a[i];
			a[i] = 0;
		}
	for (int i = N; i > 1; i--)
		a[fa[q[i]]] -= a[q[i]];
	for (int i = 1; i <= N; i++)
		if ((a[i] = -a[i]) < 0)
		{
			puts("NO");
			return 0;
		}
	for (int i = N; i; i--)
	{
		int u = q[i];
		if (!next[head[u]])
			continue;
		long long SUM = 0, MAX = 0;
		for (int e = head[u]; e; e = next[e])
			if (to[e] != fa[u])
			{
				SUM += b[to[e]];
				MAX = std::max(MAX, b[to[e]]);
			}
		if (a[u] > std::min(SUM >> 1, SUM - MAX))
		{
			puts("NO");
			return 0;
		}
		b[u] = SUM - (a[u] << 1);
	}
	puts(b[root] ? "NO" : "YES");
	return 0;
}
