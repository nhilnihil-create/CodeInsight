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
	int n;
	cin >> n;
	int divs = 0, ones = 0;
	rep(i, 0, n)
	{
		int x;
		cin >> x;
		if (x % 2)
			ones++;
		if (x % 4 == 0)
			divs++;
	}
	if (divs == 0 && ones > 0)
		cout << "No";
	else if (divs + ones == n && ones <= divs + 1)
		cout << "Yes";
	else if (divs < ones)
		cout << "No";
	else
		cout << "Yes";
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
