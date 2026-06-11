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

const int MAXN = 100005;

int n, a[MAXN], d[MAXN];
vector <int> adj[MAXN];
LL f[MAXN];

inline void GG()
{
	puts("NO");
	exit(0);
}

inline void Dfs(int x, int p)
{
	if (d[x] == 1)
		f[x] = a[x];
	else
	{
		f[x] = a[x] << 1;
		for (auto y : adj[x])
			if (y ^ p)
			{
				Dfs(y, x), f[x] -= f[y];
				if (f[y] > a[x])
					GG();
			}
		if (f[x] < 0 || f[x] > a[x])
			GG();
	}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1, x, y; i < n; i ++)
		x = Read(), y = Read(), adj[x].pb(y), adj[y].pb(x), d[x] ++, d[y] ++;
	if (n == 2)
		return puts(a[1] == a[2] ? "YES" : "NO"), 0;
	for (int i = 1; i <= n; i ++)
		if (d[i] ^ 1)
		{
			Dfs(i, 0);
			return puts(f[i] ? "NO" : "YES"), 0;
		}
}
