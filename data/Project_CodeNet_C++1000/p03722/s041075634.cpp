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

bool calcShortest(vector<Edge>& list, int s, int maxV, vector<ll>& d, vector<bool>& negativeLoop)
{
	for (auto i = 0; i < maxV; ++i)
	{
		d.push_back(LLONG_MAX);
		negativeLoop.push_back(false);
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
				if (i >= maxV)
				{
					negativeLoop[e.to] = true;
				}
			}
		}
		if (!isUpdate)
		{
			break;
		}
		if (i >= maxV)
		{
			isLoop = true;
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
	vector<bool> negativeLoop;
	calcShortest(list, 0, N, d, negativeLoop);
	if(negativeLoop[N - 1])
	{
		cout << "inf" << endl;
	}
	else
	{
		cout << -d[N - 1] << endl;
	}

	return 0;
}