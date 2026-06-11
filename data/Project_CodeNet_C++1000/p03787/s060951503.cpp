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

int n, m;
vector<int> edg[MAXN];
int sumb = 0, numb = 0, sumn = 0, numn = 0;
int col[MAXN], size[MAXN];
long long ans = 0;

bool dfs(int x, int fa, int c)
{
	if(col[x] != -1)
		return col[x] == c;
	col[x] = c;
	size[x] = 1;
	bool ret = true;
	for(int i = 0; i < edg[x].size(); i++)
		if(edg[x][i] != fa)
		{
			int y = edg[x][i];
			if(col[y] == -1)
				ret &= dfs(y, x, c ^ 1), size[x] += size[y];
			else
				ret &= dfs(y, x, c ^ 1);
		}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		edg[x].push_back(y), edg[y].push_back(x);
	}

	memset(col, -1, sizeof(col));
	for(int i = 1; i <= n; i++)
		if(col[i] == -1)
		{
			bool flag = dfs(i, 0, 0);
			int sz = size[i];
			if(sz > 1)
			{
				if(flag)
					sumb += sz, numb += 1;
				else
					sumn += sz, numn += 1;
			}
		}
	// cerr << sumb << ' ' << sumn << endl;
	ans = (long long)n * n;
	ans -= (long long)(sumb + sumn) * (sumb + sumn);
	ans += (long long)(numb + numn) * (numb + numn) + (long long)numb * numb;

	cout << ans << endl;

	return 0;
}
