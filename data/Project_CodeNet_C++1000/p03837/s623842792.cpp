#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

struct EdgeA
{
	int to;
	ll cost;
};

void calcAllShortest(vector<vector<EdgeA>>& G, vector<vector<ll>>& d)
{
	auto numV = (int)G.size();
	for (auto i = 0; i < numV; ++i)
	{
		d.push_back(vector<ll>(numV, LLONG_MAX));

		for (auto v : G[i])
		{
			d[i][v.to] = v.cost;
		}
		d[i][i] = 0;
	}

	for (auto k = 0; k < numV; ++k)
	{
		for (auto i = 0; i < numV; ++i)
		{
			for (auto j = 0; j < numV; ++j)
			{
				if (d[i][k] >= LLONG_MAX || d[k][j] >= LLONG_MAX)
				{
					continue;
				}
				auto kd = d[i][k] + d[k][j];
				if (d[i][j] > kd)
				{
					d[i][j] = kd;
				}
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<EdgeA>> G(N);
	for (auto i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		G[a].push_back({ b, c });
		G[b].push_back({ a, c });
	}

	vector<vector<ll>> d;
	calcAllShortest(G, d);

	auto ans = 0;
	for (auto i = 0; i < N; ++i)
	{
		for (auto& e : G[i])
		{
			if (e.to < i)
			{
				continue;
			}

			if (d[i][e.to] < e.cost)
			{
				++ans;
			}
		}
	}

	cout << ans << endl;

	return 0;
}