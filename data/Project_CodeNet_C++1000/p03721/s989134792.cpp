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
	ll n, k;
	cin >> n >> k;
	multiset<pair<ll, ll>> s;
	while (n--)
	{
		ll a, b;
		cin >> a >> b;
		s.insert({a, b});
	}
	for (auto i : s)
	{
		ll a = i.first;
		ll b = i.second;
		k -= b;
		if (k <= 0)
		{
			cout << a;
			break;
		}
	}
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