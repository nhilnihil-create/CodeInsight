#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;

int n;
int a[MaxN + 1];

vector<int> adj[MaxN + 1];

bool ok = true;

int dfs(int u, int prev)
{
	if (adj[u].size() == 1u)
		return a[u];

	int w = a[u] << 1;
	for (int v : adj[u])
		if (v != prev)
		{
			int l = dfs(v, u);
			if (l > a[u])
				ok = false;
			w -= l;
		}

	if (w < 0 || (!prev && w) || w > a[u])
		ok = false;

	return w;
}

int main()
{
	cin >> n;
	for (int u = 1; u <= n; ++u)
		a[u] = getint();
	for (int i = 1; i < n; ++i)
	{
		int u = getint(), v = getint();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (n == 2)
		ok = a[1] == a[2];

	for (int u = 1; u <= n; ++u)
		if (adj[u].size() > 1u)
		{
			dfs(u, 0);
			break;
		}

	puts(ok ? "YES" : "NO");

	return 0;
}