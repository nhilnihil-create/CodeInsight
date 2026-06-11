#define _CRT_SECURE_NO_WARNINGS
#define y1 klfjvkldfngldf

#pragma comment(linker, "/STACK:400000000")

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <functional>
#include <numeric>
#include <random>
#include <memory.h>
#include <time.h>

using namespace std;

typedef long long LL;

const int N = 100000;

vector<int> G[N];
int color[N];

int go(int x, int c)
{
	int res = 0;
	color[x] = c;
	for (int i = 0; i < G[x].size(); ++i)
	{
		int to = G[x][i];
		if (color[to] == -1)
			res |= go(to, c ^ 1);
		if (color[to] == color[x])
			res = 1;
	}
	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	fill(color, color + n, -1);

	int even = 0;
	int odd = 0;
	int alone = 0;
	for (int i = 0; i < n; ++i)
	{
		if (color[i] != -1)
			continue;
		if (go(i, 0))
			odd++;
		else
		{
			if (G[i].size() == 0)
				alone++;
			else
				even++;
		}
	}
	LL res = (LL)alone * alone + (LL)2 * alone * (n - alone);
	res += (LL)2 * even * even;
	res += (LL)odd * odd;
	res += (LL)2 * even * odd;
	cout << res << endl;
	return 0;
}