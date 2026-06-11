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
	multiset<int> s;
	int sum = 0;
	while (n--)
	{
		int x;
		cin >> x;
		sum += x;
		s.insert(x);
	}
	if (sum % 10)
		cout << sum;
	else
	{
		multiset<int>::iterator it;
		for (it = s.begin(); it != s.end() && *it % 10 == 0; it++)
			;
		if (it != s.end())
			cout << sum - *it;
		else
			cout << 0;
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