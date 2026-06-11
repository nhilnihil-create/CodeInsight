#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int k, t, ans;
	vector<int> v;

	cin >> k >> t;
	rep(i, t)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.rbegin(), v.rend());	
	ans = v[0] - 1;
	for(int i = 1; i < t; i++)
	{
		ans -= v[i];
		if (ans <= 0)
		{
			ans = 0;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
