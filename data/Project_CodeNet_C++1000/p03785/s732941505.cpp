#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, c, k, cnt, ans;
	long long tmp;
	cin >> n >> c >> k;
	vector<long long> t(n);
	bool ok;

	rep(i, n) cin >> t[i];
	sort(t.begin(), t.end());
	ok = true;
	ans = 0;
	cnt = 0;
	tmp = t[0];
	rep(i, n)
	{
		if (t[i] <= tmp + k)
		{
			cnt++;
			if (cnt > c)
				ok = false;
		}
		else
			ok = false;
		if (!ok)
		{
			tmp = t[i];
			ans++;
			cnt = 1;
			ok = true;
		}
	}
  	ans++;
	cout << ans << endl;
	return 0;
}
