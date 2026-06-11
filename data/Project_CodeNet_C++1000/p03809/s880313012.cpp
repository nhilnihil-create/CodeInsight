#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

namespace io
{
	const int maxb = 1 << 15;
	char b[maxb], *s = b, *t = b;
	bool Getchar(char &ch)
	{
		return ch = s == t && (t = (s = b) + fread(b, 1, maxb, stdin)) == b ? 0 : *s ++;
	}
}

int Getint()
{
	using namespace io;
	char ch;
	while (Getchar(ch) && (ch < '0' || ch > '9'));
	int s = ch - '0';
	while (Getchar(ch) && ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0';
	return s;
}

const int maxn = 1e5 + 10;

struct Edge
{
	Edge *next;
	int to;
} pool[maxn * 2], *p = pool, *head[maxn];

void AddEdge(int fr, int to)
{
	p->to = to;
	p->next = head[fr];
	head[fr] = p ++;
}

int a[maxn], d[maxn], f[maxn];

bool Dfs(int u, int fa)
{
	if (d[u] == 1)
	{
		f[u] = a[u];
		return true;
	}
	int s = 0, cnt = 0, Mx = 0;
	for (Edge *t = head[u]; t; t = t->next)
	{
		int v = t->to;
		if (v == fa) continue;
		if (!Dfs(v, u)) return false;
		s += f[v];
		if (s > a[u] * 2) return false;
		Mx = max(Mx, f[v]);
	}
	int x = s - a[u];
	if (x < 0) return false;
	s = min(s - Mx, s / 2);
	if (x > s) return false;
	f[u] = a[u] - x;
	return true;
}

int main()
{
	int n = Getint();
	for (int i = 1; i <= n; ++ i) a[i] = Getint();
	if (n == 2)
	{
		if (a[1] == a[2]) puts("YES"); else puts("NO");
		return 0;
	}
	memset(head, 0, sizeof head);
	for (int i = 1; i < n; ++ i)
	{
		int u = Getint(), v = Getint();
		++ d[u], ++ d[v];
		AddEdge(u, v);
		AddEdge(v, u);
	}
	int root;
	for (root = 1; d[root] == 1; ++ root);
	if (!Dfs(root, 0) || f[root]) puts("NO"); else puts("YES");
	return 0;
}
