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
vector<int> adj[MaxN + 1];

int dfs(int u, int fa)
{
	int w = 0;
	for (int v : adj[u])
		if (v != fa)
			w ^= dfs(v, u) + 1;
	return w;
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int u = getint(), v = getint();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << (dfs(1, 0) ? "Alice" : "Bob");
	cout << endl;

	return 0;
}