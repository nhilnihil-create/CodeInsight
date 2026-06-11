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
	string s;
	cin >> s;
	s.replace(5, 1, " ");
	s.replace(13, 1, " ");
	cout << s;
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