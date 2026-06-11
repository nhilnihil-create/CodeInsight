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
	string s;
	ll K;
	cin >> s >> K;

	for (auto i = 0; i < s.length(); ++i)
	{
		if (s[i] == 'a')
		{
			continue;
		}

		auto diff = (ll)('z' - s[i]) + 1;
		if (diff > K)
		{
			continue;
		}

		K -= diff;
		s[i] = 'a';
	}

	if (K > 0)
	{
		auto last = s.length() - 1;
		auto mod = (ll)('z' - 'a') + 1;
		K %= mod;
		auto diff = (ll)('z' - s[last]) + 1;
		if (K >= diff)
		{
			s[last] = 'a' + (K - diff);
		}
		else
		{
			s[last] = s[last] + K;
		}
	}

	cout << s << endl;

	return 0;
}