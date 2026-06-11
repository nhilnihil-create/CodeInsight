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
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> index(N + 1);
	for (auto i = 0; i < N; ++i)
	{
		cin >> a[i];
		index[a[i]] = i;
	}

	auto result = 0ll;
	set<int> s;
	for (auto i = 1ll; i <= N; ++i)
	{
		auto j = index[i];
		auto it = s.lower_bound(j);
		auto left = -1;
		auto right = N;
		if (it == s.end())
		{
			if (s.size() > 0)
			{
				--it;
				left = *it;
			}
		}
		else if (it == s.begin())
		{
			right = *it;
		}
		else
		{
			right = *it;
			--it;
			left = *it;
		}

		result += i * (right - j) * (j - left);
		s.insert(j);
	}

	cout << result << endl;

	return 0;
}