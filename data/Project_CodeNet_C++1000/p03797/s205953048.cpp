#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define peek(v)      \
	for (auto i : v) \
		cout << i << ' ';

void solve()
{
	ll S, c;
	cin >> S >> c;
	if (S >= c / 2)
		cout << c / 2;
	else
	{
		c -= S * 2;
		cout << S + c / 4;
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