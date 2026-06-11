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
	int N, K;
	cin >> N >> K;
	vector<ll> a(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	auto ans = LLONG_MAX;
	for (auto i = 0; i < (1 << (N - 1)); ++i)
	{
		auto next = a[0] + 1;
		auto sum = 0ll;
		auto num = 1;
		for (auto j = 0; j < N - 1; ++j)
		{
			if (a[j + 1] < next)
			{
				auto bit = 1 << j;
				if ((i & bit) != 0)
				{
					sum += next - a[j + 1];
					++num;
					++next;
				}
			}
			else
			{
				++num;
				next = a[j + 1] + 1;
			}
		}

		if (num >= K)
		{
			ans = min(ans, sum);
		}
	}

	cout << ans << endl;

	return 0;
}