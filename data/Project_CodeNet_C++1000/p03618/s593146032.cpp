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
	string A;
	cin >> A;

	auto ans = 1ll + (ll)A.length() * ((ll)A.length() - 1) / 2;

	vector<ll> num(30);
	for (auto i = 0; i < (int)A.length(); ++i)
	{
		++num[A[i] - 'a'];
	}

	for (auto i = 0; i < (int)num.size(); ++i)
	{
		if (num[i] <= 1)
		{
			continue;
		}

		ans -= num[i] * (num[i] - 1) / 2;
	}

	cout << ans << endl;

	return 0;
}