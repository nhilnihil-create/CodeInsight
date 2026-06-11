#include <bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d\n", x)
#define lowbit(x) (x & -x)
#define ll long long
#define N 100010
using namespace std;
int n, m, col[N], tot = 0, head[N], maxx[N], q;
struct Xiao
{
	int next, to;
}e[N * 2];
struct Wang
{
	int v, d, c;
}qvq[N];
inline void add(int x, int y)
{
	e[++tot].next = head[x];
	e[tot].to = y;
	head[x] = tot;
}
inline void dfs(int d, int sc, int x, int fa)
{
	if (d <= maxx[x]) return;
	maxx[x] = d;
	if (col[x] == 0) col[x] = sc;
	for (int i = head[x]; i; i = e[i].next)
	{
		int y = e[i].to;
		if (y == fa) continue;
		dfs(d - 1, sc, y, x);
	}
}
int main()
{
	sc(n);
	sc(m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		sc(a);
		sc(b);
		add(a, b);
		add(b, a);
	}
	sc(q);
	for (int i = 1; i <= q; i++)
	{
		sc(qvq[i].v);
		sc(qvq[i].d);
		sc(qvq[i].c);
	}
	memset(maxx, -1, sizeof maxx);
	for (int i = q; i >= 1; i--)
	dfs(qvq[i].d, qvq[i].c, qvq[i].v, 0);
	for (int i = 1; i <= n; i++)
	printf("%d\n", col[i]);
	return 0;
}
