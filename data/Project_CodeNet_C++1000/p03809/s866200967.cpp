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

int n, deg[N];

int64 A[N];

VI edge[N];

void dfs(int u, int fa)
{
	if (deg[u] <= 1) return;
	int64 x = 0, cnt = 0, la = 0;
	for (auto v : edge[u])
	{
		if (v == fa) continue;
		dfs(v, u);
		x += A[v];
		la = max(la, A[v]);
	}
	cnt = min(x >> 1, x - la);
	if (x >= A[u] && x <= A[u] + cnt)
	{
		int64 c = x - A[u];
		A[u] -= c;
	}
	else
	{
		puts("NO");
		exit(0);
	}
}

int main()
{
	gi(n);
	for (int i = 1; i <= n; ++i) gi(A[i]);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		gii(a, b);
		edge[a].pb(b);
		edge[b].pb(a);
		++deg[a], ++deg[b];
	}
	if (n == 2)
	{
		puts(A[1] == A[2] ? "YES" : "NO");
		return 0;
	} 
	int root = 1;
	for (; deg[root] == 1; ++root);
	dfs(root, 0);
	if (!A[root]) puts("YES");
	else puts("NO");
}
