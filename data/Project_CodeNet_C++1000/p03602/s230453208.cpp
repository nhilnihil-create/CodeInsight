#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void ARC083D()
{
	int N;
	cin >> N;
	vector<vector<ll> > A(N, vector<ll>(N));
	priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int> > >, greater<pair<ll, pair<int, int> > > >  qu;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			ll x;
			cin >> x;
			A[i][j] = x;
			if (j > i)
				qu.push({ x, {i,j} });
		}
	}

	struct Edge {
		int to_;
		ll dist_;
	};
	vector<vector<Edge> > graph(N);
	vector<vector<ll> > dist(N, vector<ll>(N, 100000000000000000));
	for (int i = 0; i < N; ++i)
	{
		dist[i][i] = 0;
	}

	ll total = 0;
	while (!qu.empty())
	{
		auto p = qu.top();
		qu.pop();
		int x1 = p.second.first;
		int x2 = p.second.second;

		if (dist[x1][x2] <= p.first)
			continue;
		graph[x1].push_back({ x2, p.first });
		graph[x2].push_back({ x1, p.first });
		total += p.first;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				dist[i][j] = min(dist[i][j], min(dist[i][x1] + dist[x2][j], dist[i][x2] + dist[x1][j]) + p.first);
				dist[j][i] = dist[i][j];
				if (dist[i][j] < A[i][j])
				{
					cout << -1 << endl;
					return;
				}
			}
		}
	}
	cout << total << endl;
}

int main()
{
	ARC083D();
	return 0;
}