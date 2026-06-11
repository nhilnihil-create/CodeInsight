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

int main()
{
	int N;
	cin >> N;

	auto logN = (int)floor(log2(N));
	vector<vector<int>> parent(logN + 1, vector<int>(N, -1));

	vector<ll> x(N);
	for (auto& temp : x)
	{
		cin >> temp;
	}

	ll L;
	cin >> L;

	auto r = 0;
	for (auto l = 0; l < N; ++l)
	{
		while (r < N && (x[r] - x[l]) <= L)
		{
			++r;
		}

		parent[0][l] = r - 1;
	}

	for (auto i = 0; i < logN; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			if (parent[i][j] >= 0)
			{
				parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
	}

	int Q;
	cin >> Q;

	vector<int> ans;
	for (auto i = 0; i < Q; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		if (a > b)
		{
			swap(a, b);
		}

		auto l = 0;
		auto h = N;
		while (l <= h)
		{
			auto mid = (l + h) / 2;
			auto p = a;
			for (auto j = logN; j >= 0; --j)
			{
				if (((mid >> j) & 1) > 0)
				{
					p = parent[j][p];

					if (p < 0)
					{
						p = N;
						break;
					}
				}
			}

			if (p >= b)
			{
				h = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}

		ans.push_back(l);
	}

	for (auto temp : ans)
	{
		cout << temp << endl;
	}

	return 0;
}