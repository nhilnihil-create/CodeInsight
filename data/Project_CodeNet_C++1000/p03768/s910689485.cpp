#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 1e5 + 5;
int col[N], Max[N], v[N], d[N], c[N];
vector<int> G[N];

void dfs(int u, int i)
{
	if (!col[u]) col[u] = c[i];
	for (int v : G[u])
		if (Max[u] - 1 > Max[v])
			Max[v] = Max[u] - 1, dfs(v, i);
}

int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	memset(Max, -1, sizeof(Max));
	int q = read();
	for (int i = 1; i <= q; ++i)
		v[i] = read(), d[i] = read(), c[i] = read();
	for (int i = q; i >= 1; --i)
		if (d[i] > Max[v[i]]) Max[v[i]] = d[i], dfs(v[i], i);
	
	for (int i = 1; i <= n; ++i)
		printf("%d\n", col[i]);
	
	return 0;
}
