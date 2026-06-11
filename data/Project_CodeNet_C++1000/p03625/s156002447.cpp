#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n; cin >> n;
	map<long long, long long> m;
	long long x, y;

	rep(i, n)
	{
		long long a;
		cin >> a;
		m[a]++;
	}
	x = y = 0;
	for (auto p : m)
	{
		auto k = p.first;
		auto v = p.second;
		if (v >= 2)
		{
			if (x < k)
			{
				y = x;
				x = k;
			}
		}
		if (v >= 4)
			y = x;
	}
	cout << x * y << endl;
}
