#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, cnt, ans;
	cin >> n;
	map<int, int> mp;
	rep(i, n)
	{
		int a;
		cin >> a;
		mp[a]++;
	}
	ans = cnt = 0;
	for (auto p : mp)
	{
		if (p.second % 2 == 1)
			ans++;
		else
			cnt++;
	}
	if (cnt % 2 == 0)
		ans += cnt;
	else
		ans += cnt - 1;
	cout << ans << endl;
	return 0;
}
