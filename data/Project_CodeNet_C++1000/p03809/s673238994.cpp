#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5.5E5;
long long f[MAXN];
long long value[MAXN];
int D[MAXN];
vector <int> adj[MAXN];
int n, root;

void getAns(int u, int fa)
{
	long long maxLine = 0;
	long long allLine = 0;
	for (int v : adj[u])
	{
		if (v == fa)
			continue;
		getAns(v, u);
		
		maxLine = max(maxLine, f[v]),
		allLine += f[v];
	}
	
	if (!allLine)
	{
//		assert(adj[u].size() == 1);
		f[u] = value[u];
		return ;
	}
	
	f[u] = 2ll * value[u] - allLine;
	long long restLine = allLine - maxLine;
	
	if (f[u] < 0 || f[u] > value[u] || maxLine - f[u] > restLine)
		puts("NO"), exit(0);
}

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1;i <= n; ++i)
		cin >> value[i];
	
	if (n == 2)
	{
		puts((value[1] == value[2]) ? "YES" : "NO");
		return 0;
	}
	
	for (int i = 1;i < n; ++i)
	{
		int u = 0, v = 0;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		D[u]++, D[v] ++;
		
		if (D[u] > 1)
			root = u;
		if (D[v] > 1)
			root = v;
	}
	
	getAns(root, 0);
	if (f[root])
		puts("NO");
	else
		puts("YES");
	
	return 0;
}

/*
up + 2 * down = all
up + down = value
down = all - value
up + 2 * (all - value) = all
up = 2 * value - all
*/