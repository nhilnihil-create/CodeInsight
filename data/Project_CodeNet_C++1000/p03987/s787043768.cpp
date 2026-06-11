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
	vector<pair<int, int>> a;
	for (auto i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		a.push_back({ temp, i + 1 });
	}

	sort(a.begin(), a.end());
	set<int> s;
	s.insert(0);
	s.insert(N + 1);
	auto ans = 0ll;
	for (auto i = 0; i < N; ++i)
	{
		auto& p = a[i];
		auto it = s.upper_bound(p.second);
		auto right = *it;
		--it;
		auto left = *it;
		ans += (ll)(p.second - left) * (right - p.second) * p.first;
		s.insert(p.second);
	}

	cout << ans << endl;

	return 0;
}