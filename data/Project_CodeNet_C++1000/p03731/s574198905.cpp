#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long n, t, T, tmp, ans;
	cin >> n >> T >> tmp;

	ans = 0;
	rep(i, n - 1)
	{
		cin >> t;
		ans += min(T, t - tmp);
		tmp = t;
	}
	ans += T;
	cout << ans << endl;
	return 0;
}
