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
	int n;
	cin >> n;
	if (n < 1200)
		cout << "ABC";
	else
		cout << "ARC";
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