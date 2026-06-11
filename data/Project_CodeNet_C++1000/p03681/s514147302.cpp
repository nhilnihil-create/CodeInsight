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

ll mul(ll a, ll b)
{
	return ((a % MOD) * (b % MOD)) % MOD;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	if (abs(n - m) > 1)
		cout << 0;
	else
	{
		int ans = 1;
		rep(i, 1, n + 1)
			ans = mul(ans, i);
		rep(i, 1, m + 1)
			ans = mul(ans, i);
		if (m == n)
			cout << mul(ans, 2);
		else
			cout << ans;
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