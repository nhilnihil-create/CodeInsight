#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define peek(v)      \
	for (auto i : v) \
		cout << i << ' ';
#define rep(i, begin, end) \
	for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

void solve()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int area1 = a * b;
	int area2 = c * d;
	if (area1 > area2)
		cout << area1;
	else
		cout << area2;
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