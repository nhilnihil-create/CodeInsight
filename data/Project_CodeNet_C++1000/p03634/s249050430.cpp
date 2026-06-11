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

struct EdgeD
{
	int to;
	ll cost;
};

void calcShortestD(vector<vector<EdgeD>>& G, int s, int maxV, vector<ll>& d)
{
	for (auto i = 0; i < maxV; ++i)
	{
		d.push_back(LLONG_MAX);
	}
	d[s] = 0;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push({ 0, s });

	while (!q.empty())
	{
		auto p = q.top();
		q.pop();
		auto v = p.second;
		if (d[v] < p.first)
		{
			continue;
		}

		for (auto& e : G[v])
		{
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				q.push({ d[e.to], e.to });
			}
		}
	}
}



int main()
{
	int N;
	cin >> N;

	vector<vector<EdgeD>> G(N);
	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		--a;
		--b;
		G[a].push_back({ b, c });
		G[b].push_back({ a, c });
	}

	int Q, K;
	cin >> Q >> K;
	--K;

	vector<ll> d;
	calcShortestD(G, K, N, d);

	vector<ll> ans;
	for (auto i = 0; i < Q; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		ans.push_back(d[x] + d[y]);
	}

	for (auto i = 0; i < Q; ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}