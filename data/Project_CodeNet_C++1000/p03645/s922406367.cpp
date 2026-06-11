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
	ll e, m;
	cin >> e >> m;
	map<ll, set<ll>> mm;
	rep(i, 0, m)
	{
		ll x, y;
		cin >> x >> y;
		mm[x].insert(y);
	}
	for(auto i: mm[1])
	{
		for(int j: mm[i])
		{
			if(j == e)
			{
				cout << "POSSIBLE";
				return;
			}
		}
	}
	cout << "IMPOSSIBLE";
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