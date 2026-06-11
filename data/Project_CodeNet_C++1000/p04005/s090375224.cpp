#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long a, b, c, ans;
	cin >> a >> b >> c;
	ans = 0;
	if (!(a % 2 == 0 || b % 2 == 0 || c % 2 == 0))
		ans = min(a * b, min(b * c, a * c));
	cout << ans << endl;
	return 0;
}
