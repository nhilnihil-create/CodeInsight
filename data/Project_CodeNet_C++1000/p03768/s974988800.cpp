#include<bits/stdc++.h>
using namespace std;

int n, m, q, dot[100001] = {}, maxp[100001] = {};
vector<int> g[100001];
int v[100001], d[100001], c[100001];

void dfs(int col, int step, int f)
{
	if (dot[f] == 0) dot[f] = col;
	
	if (maxp[f] >= step) return;
	maxp[f] = step;

	int length = g[f].size();
	for (int i = 0; i < length; i++)
	{
		if (step - 1 >= 0) dfs(col, step - 1, g[f][i]);
	}
}

int main()
{
	cin >> n >> m;
	int f, t;
	for (int i = 1; i <= m; i++)
	{
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	
	cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> v[i] >> d[i] >> c[i];
		
	for (int i = q; i >= 1; i--)
	{
		dfs(c[i], d[i], v[i]);
	}	
	
	for (int i = 1; i <= n; i++)
		cout << dot[i] << '\n';
	
	return 0;
}