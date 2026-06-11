#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 2005;
int u[N], v[N], dep[N];
vector<int> G[N];

void dfs(int u, int fa)
{
	for (int v : G[u]) if (v != fa)
		dep[v] = dep[u] + 1, dfs(v, u);
}

int main()
{
	int n = read(), k = read();
	for (int i = 1; i < n; ++i)
	{
		u[i] = read();
		v[i] = read();
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	
	int ans = n;
	if (k & 1)
	{
		for (int i = 1; i < n; ++i)
		{
			dep[u[i]] = 0;
			dep[v[i]] = 0;
			dfs(u[i], v[i]);
			dfs(v[i], u[i]);
			
			int cnt = 0;
			for (int j = 1; j <= n; ++j)
				if (dep[j] > k / 2) ++cnt;
			ans = min(ans, cnt);
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			dep[i] = 0;
			dfs(i, 0);
			
			int cnt = 0;
			for (int j = 1; j <= n; ++j)
				if (dep[j] > k / 2) ++cnt;
			ans = min(ans, cnt);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
