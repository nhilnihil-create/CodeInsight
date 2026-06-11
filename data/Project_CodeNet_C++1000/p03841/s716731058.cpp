#include <bits/stdc++.h>

const int N = 5e5 + 50;

int n, m, id[N], p[N], c[N], co[N];
std::pair<int, int> a[N];
bool active[N], qwq[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1; char ch;
	do
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int main()
{
	n = read(), m = n * n;
	for (int i = 1; i <= n; ++i) a[i] = std::make_pair(read(), i), c[i] = i, p[a[i].first] = i, qwq[a[i].first] = true;
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) id[i] = a[i].second;
	int t = 1;
	for (int i = 1; i <= m; ++i)
	{
		if (p[i] == 0)
		{
			while (t <= n && a[t].second == 1)
			{
				++t;
			}
			if (t == n + 1) break;
			if (i >= a[t].first) { return puts("No"), 0; }
			
			p[i] = id[t]; ++co[id[t]]; --a[t].second;
		}
		else
		{
			if (co[p[i]] != p[i] - 1) return puts("No"), 0;
			active[p[i]] = true;
		}
	}
	t = 1;
	for (int i = 1; i <= m; ++i)
	{
		if (!p[i])
		{
			while (co[id[t]] == n - 1) ++t;
			++co[id[t]]; p[i] = id[t];
			if (!active[id[t]]) return puts("No"), 0;
		}
		else if (qwq[i])
		 active[p[i]] = true;
	}
	puts("Yes");
	for (int i = 1; i <= m; ++i) printf("%d ", p[i]);
	return 0;
}