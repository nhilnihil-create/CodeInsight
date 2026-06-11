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

const int N = 1e5 + 10, M = 1e5 + 10;

int n, m;

bool flag;

VI edge[N];

int co[N];

int O, P, Q;

void dfs(int i, int x)
{
	co[i] = x;
	for (auto j : edge[i])
	{
		if (co[j])
		{
			if (co[j] != (co[i] ^ 1)) flag = 0;
		}
		else
		{
			dfs(j, x ^ 1);
		}
	}
}

int main()
{
	gii(n, m);
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		gii(u, v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!co[i])
		{
			if (!SZ(edge[i]))
			{
				++O;
				continue;
			}
			flag = 1;
			dfs(i, 2);
			if (flag) ++Q;
			else ++P;
		}
	}
	long long ans = 2LL * O * n - 1LL * O * O + 1LL * P * P + 2LL * P * Q + 2LL * Q * Q;
	printf("%lld\n", ans);
	return 0;
}