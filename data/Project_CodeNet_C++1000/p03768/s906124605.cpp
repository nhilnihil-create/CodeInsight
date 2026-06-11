//waz
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))

int F()
{
	char ch;
	int x, a;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') ch = getchar(), a = -1;
	else a = 1;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + ch - '0';
	return a * x;
}

const int N = 1e5 + 10;

int n, m;

VI edge[N];

int mxd[N], co[N];

void dfs(int u, int d, int c)
{
	if (d <= mxd[u]) return;
	if (!co[u]) co[u] = c;
	mxd[u] = d;
	for (auto v: edge[u])
		dfs(v, d - 1, c);
}

int v[N], d[N], c[N];

int main()
{
	gii(n, m);
	for (int i = 1; i <= n; ++i) mxd[i] = -1;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		gii(u, v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	int q;
	gi(q);
	for (int i = 1; i <= q; ++i)
		giii(v[i], d[i], c[i]);
	for (int i = q; i; --i)
		dfs(v[i], d[i], c[i]);
	for (int i = 1; i <= n; ++i)
		printf("%d\n", co[i]);
}