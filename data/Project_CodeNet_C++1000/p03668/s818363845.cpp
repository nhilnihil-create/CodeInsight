#include <bits/stdc++.h>

const int N = 2e5 + 50;

int head[N], nxt[N], ver[N], cnt, n, SG[N];

inline void add(int u, int v)
{
	nxt[++cnt] = head[u], ver[cnt] = v, head[u] = cnt;
}

inline void solve(int x, int fa = -1)
{
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (y != fa)
		{
			solve(y, x);
			SG[x] ^= SG[y] + 1;
		}
	}
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	n = read();
	for (int i = 1; i < n; ++i)
	{
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
	solve(1);
	puts(SG[1] ? "Alice" : "Bob");
	return 0;
}
