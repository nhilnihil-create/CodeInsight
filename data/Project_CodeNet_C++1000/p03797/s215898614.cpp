#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long n, m, ans;
	cin >> n >> m;
	m /= 2;
	ans = 0;
	ans = min(n, m);
	m -= ans;
	if (m > 0)
		ans += m / 2;
	cout << ans << endl;
	return 0;
}
