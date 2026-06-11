#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define rep(i, s, e) for (auto i = s; i < e; i++)
#define peek(v)      \
	for (auto i : v) \
		cout << i << ' ';

void solve()
{
	int n;
	cin >> n;
	ll x, y, X, Y, a, i;
	x = y = X = Y = i = 0;
	while (cin >> a && ++i)
	{
		x += a, y += a;
		if (i % 2)
		{
			if (x > -1)
				X += x + 1, x = -1;
			if (y < 1)
				Y += 1 - y, y = 1;
		}
		else
		{
			if (y > -1)
				Y += y + 1, y = -1;
			if (x < 1)
				X += 1 - x, x = 1;
		}
	}
	cout << min(X, Y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	cerr << "\n\n~" << 500 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}