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
	ll x;
	cin >> N >> x;
	vector<ll> a(N * 2);
	vector<ll> list(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> a[i];
		a[i + N] = a[i];
		list[i] = a[i];
	}

	auto ans = LLONG_MAX;
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			auto next = j - i + N;
			list[j] = min(list[j], a[next]);
		}
		auto sum = 0ll;
		for (auto j = 0; j < N; ++j)
		{
			sum += list[j];
		}
		sum += x * i;
		ans = min(ans, sum);
	}

	cout << ans << endl;

	return 0;
}