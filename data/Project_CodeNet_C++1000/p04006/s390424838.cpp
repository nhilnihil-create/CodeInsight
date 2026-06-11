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
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ll N, x;
	cin >> N >> x;
	vector<ll> a(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	vector<vector<ll>> m(N, vector<ll>(N));
	for (auto i = 0; i < N; ++i)
	{
		auto temp = LLONG_MAX;
		for (auto j = 0; j < N; ++j)
		{
			auto k = (i - j + N) % N;
			temp = min(temp, a[k]);
			m[i][j] = temp;
		}
	}

	auto result = LLONG_MAX;
	for (auto i = 0; i < N; ++i)
	{
		auto sum = 0ll;
		for (auto j = 0; j < N; ++j)
		{
			sum += m[j][i];
		}
		sum += x * i;
		result = min(result, sum);
	}

	cout << result << endl;

	return 0;
}