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

const int MAXN = 100000 + 10000;

int n;
int a[MAXN], fa[MAXN];
long long b[MAXN];
vector<int> edg[MAXN];

void yes()
{
	cout << "YES" << endl;
	exit(0);
}

void no()
{
	cout << "NO" << endl;
	exit(0);
}

void dfs(int x, int father)
{
	fa[x] = father;
	b[x] = edg[x].size() > 1 ? 2 * a[x] : a[x];
	for(int i = 0; i < edg[x].size(); i++)
		if(edg[x][i] != fa[x])
		{
			int y = edg[x][i];
			dfs(y, x);
			b[x] -= b[y];
		}
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		edg[x].push_back(y), edg[y].push_back(x);
	}
	dfs(1, 0);
	if(b[1] != 0)
		no();
	for(int i = 1; i <= n; i++)
		if(b[i] < 0)
			no();
	for(int i = 1; i <= n; i++)
		if(edg[i].size() > 1)
		{
			if(b[i] > a[i]) no();
			for(int j = 0; j < edg[i].size(); j++)
				if(edg[i][j] != fa[i])
					if(b[edg[i][j]] > a[i])
						no();
		}
	yes();

	return 0;
}
