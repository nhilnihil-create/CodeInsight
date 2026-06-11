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
	ll n, x;
	cin >> n >> x;
	vector<ll> t(n);
	rep(i, 0, n)
	{
		cin >> t[i];
	}
	ll total = 0;
	rep(i, 0, n - 1)
	{
		ll cur = t[i];
		ll next = t[i + 1];
		if (cur + x <= next)
			total += x;
		else
			total += t[i + 1] - t[i];
	}
	cout << total + x;
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