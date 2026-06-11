#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 505;

int n, m, d, a[MAXN][MAXN];
set <pii> vis;
vector <pii> trans;

inline void Dfs(int x, int y, int col)
{
	if (vis.find(mp(x, y)) != vis.end())
		return ;
	vis.insert(mp(x, y));
	bool fnd = 0;
	for (auto e : trans)
		if (x + e.xx >= 1 && x + e.xx <= n && y + e.yy >= 1 && y + e.yy <= m)
			a[x + e.xx][y + e.yy] = col, fnd = 1;
	if (fnd)
		Dfs(x + d, y + d, col ^ 2), Dfs(x - d, y - d, col ^ 2),
		Dfs(x + d, y - d, col ^ 1), Dfs(x - d, y + d, col ^ 1);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), d = Read();
	if (d & 1)
	{
		for (int i = 1; i <= n; i ++, putchar(10))
			for (int j = 1; j <= m; j ++)
				if (i + j & 1)
					putchar('Y');
				else
					putchar('G');
		return 0;
	}
	for (int i = 0; i < d; i ++)
		trans.pb(mp(i, 0));
	for (int i = 1; i <= (d >> 1); i ++)
		for (int j = 0; j < d; j ++)
			if ((i << 1) + j < d)
				trans.pb(mp(i + j, i)), trans.pb(mp(i + j, -i));
	d >>= 1;
	Dfs(1, 1, 0);
	for (int i = 1; i <= n; i ++, putchar(10))
		for (int j = 1; j <= m; j ++)
			if (!a[i][j])
				putchar('R');
			else if (a[i][j] == 1)
				putchar('B');
			else if (a[i][j] == 2)
				putchar('Y');
			else
				putchar('G');
	return 0;
}
