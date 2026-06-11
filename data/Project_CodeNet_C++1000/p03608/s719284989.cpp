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
	int N, M, R;
	cin >> N >> M >> R;
	vector<int> r(R);
	for (auto i = 0; i < R; ++i)
	{
		cin >> r[i];
		--r[i];
	}

	vector<vector<EdgeA>> G(N);
	for (auto i = 0; i < M; ++i)
	{
		int A, B;
		ll C;
		cin >> A >> B >> C;
		--A;
		--B;
		G[A].push_back({ B, C });
		G[B].push_back({ A, C });
	}

	vector<vector<ll>> d;
	calcAllShortest(G, d);

	vector<int> p;
	for (auto i = 0; i < R; ++i)
	{
		p.push_back(i);
	}

	auto ans = LLONG_MAX;
	do
	{
		auto sum = 0ll;
		for (auto i = 0; i < R - 1; ++i)
		{
			sum += d[r[p[i]]][r[p[i + 1]]];
		}
		ans = min(ans, sum);
	} while (next_permutation(p.begin(), p.end()) != false);
	cout << ans << endl;

	return 0;
}