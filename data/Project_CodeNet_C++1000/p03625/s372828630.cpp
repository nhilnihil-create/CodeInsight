#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define rep(i, s, e) for (auto i = s; i < e; i++)
#define peek(c)      \
	for (auto i : c) \
		cout << i << ' ';

void solve()
{
	ll n;
	cin >> n;
	map<ll, ll> m;
	rep(i, 0, n)
	{
		ll x;
		cin >> x;
		m[x]++;
	}
	vector<ll> r(2, 0);
	ll k = 0;
	for (auto it = m.rbegin(); it != m.rend() && k < 2; it++)
	{
		auto x = *it;
		if (x.second >= 2)
		{
			if (x.second >= 4 && k == 0)
			{
				r[0] = r[1] = x.first;
				break;
			}
			r[k] = x.first;
			k++;
		}
	}
	ll res = r[0] * r[1];
	cout << res;
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