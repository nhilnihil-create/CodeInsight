#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long n, a, b, ans;
	vector<long long> x;

	cin >> n >> a >> b;
	x.resize(n);
	rep(i, n) cin >> x[i];
	ans = 0;
	rep(i, n - 1)
	{
		ans += min((x[i + 1] - x[i]) * a, b);
	}
	cout << ans << endl;
	return 0;
}
