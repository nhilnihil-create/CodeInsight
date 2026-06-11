#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m;
	map<int, int> mp;
	cin >> n >> m;
	rep(i, m)
	{
		int a, b;
		cin >> a >> b;
		mp[a]++;
		mp[b]++;
	}
	for(auto p : mp)
	{
		auto k = p.first;
		auto v = p.second;
		if (v % 2 != 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
