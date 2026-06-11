#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N;
	long long W;
	cin >> N >> W;
	vector<long long> v[4];
	for (auto i = 0; i < 4; ++i)
	{
		v[i].push_back(0);
	}

	long long w1, v1;
	cin >> w1 >> v1;
	v[0].push_back(v1);
	for(auto i = 1; i < N; ++i)
	{
		long long a, b;
		cin >> a >> b;
		v[a - w1].push_back(b);
	}

	for (auto i = 0; i < 4; ++i)
	{
		sort(v[i].begin() + 1, v[i].end(), greater<long long>());
		for (auto j = 1; j < v[i].size(); ++j)
		{
			v[i][j] += v[i][j - 1];
		}
	}

	auto result = 0ll;
	for (auto i = 0; i < v[0].size(); ++i)
	{
		for (auto j = 0; j < v[1].size(); ++j)
		{
			for (auto k = 0; k < v[2].size(); ++k)
			{
				auto temp = i * w1 + j * (w1 + 1) + k * (w1 + 2);
				if (temp > W)
				{
					continue;
				}

				auto l = min((long long)v[3].size() - 1, (W - temp) / (w1 + 3));

				auto sum = v[0][i] + v[1][j] + v[2][k] + v[3][l];

				result = max(result, sum);
			}
		}
	}

	cout << result << endl;

	return 0;
}