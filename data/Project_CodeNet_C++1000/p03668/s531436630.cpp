#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 100000 + 1000;

int n;
int f[MAXN], h[MAXN];
vector<int> edg[MAXN];

void dfs(int x, int fa)
{
	f[x] = 0;
	for(int i = 0; i < edg[x].size(); i++)
		if(edg[x][i] != fa)
		{
			int y = edg[x][i];
			dfs(y, x);
			f[x] ^= (f[y] + 1);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	dfs(1, 0);
	cout << (f[1] ? "Alice" : "Bob") << endl;

	return 0;
}
