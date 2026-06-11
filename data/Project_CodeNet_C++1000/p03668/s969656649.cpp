#include <cstdio>
int N, E, head[100001], next[199999], to[199999], f[100001], fa[100001], q[100001];
int main()
{
	scanf("%d", &N);
	for (int i = 1, u, v; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		next[++E] = head[u], to[E] = v, head[u] = E;
		next[++E] = head[v], to[E] = u, head[v] = E;
	}
	int H = 0, T = 1, u;
	q[1] = 1;
	while (H < T)
		for (int e = head[u = q[++H]]; e; e = next[e])
			if (to[e] != fa[u])
				fa[q[++T] = to[e]] = u;
	for (int i = N; i > 1; i--)
		f[fa[q[i]]] ^= ++f[q[i]];
	puts(f[1] ? "Alice" : "Bob");
	return 0;
}