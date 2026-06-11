#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

const int mod = 1000000007;
long long f(long long n)
{
	if (n == 0) return 1;
	long long x = f(n / 2);
	x *= x;
	if (n % 2 != 0) x *= 2;
	return x % mod;
}

signed main(void)
{
	int n, m;
	map<int, int> mp;
	bool ok;

	cin >> n;
	rep(i, n)
	{
		int a;
		cin >> a;
		mp[a]++;
	}
	m = n;
	ok = true;
	for (auto p : mp)
	{
		auto k = p.first;
		auto v = p.second;
		if (m == n)
		{
			if (n % 2 == 0)
			{
				if (v != 2)
					ok = false;
			}
			else
				if (v != 1)
					ok = false;
		}
		else
		{
			if (!(k == n - m && v != 2))
				ok == false;
		}
		m -= 2;
	}
	if (!ok)
		cout << 0 << endl;
	else
	{
		cout << f(n / 2) << endl;
	}
	return 0;
}
