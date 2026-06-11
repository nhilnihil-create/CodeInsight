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

struct Edge
{
	int from;
	int to;
	ll cost;
};

bool calcShortest(vector<Edge>& list, int s, int maxV, vector<ll>& d)
{
	for (auto i = 0; i < maxV; ++i)
	{
		d.push_back(LLONG_MAX);
	}
	d[s] = 0;

	auto isLoop = false;
	for (auto i = 0; i <= 2 * maxV; ++i)
	{
		auto isUpdate = false;
		for (auto& e : list)
		{
			if (d[e.from] < LLONG_MAX && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				isUpdate = true;
				if (i >= maxV && e.to == maxV - 1)
				{
					isLoop = true;
				}
			}
		}
		if (!isUpdate)
		{
			break;
		}
	}

	return isLoop;
}


int main()
{
	int N, M;
	cin >> N >> M;

	vector<Edge> list;
	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		--a;
		--b;
		list.push_back({ a, b, -c });
	}

	vector<ll> d;
	if (calcShortest(list, 0, N, d) != false)
	{
		cout << "inf" << endl;
	}
	else
	{
		cout << -d[N - 1] << endl;
	}

	return 0;
}