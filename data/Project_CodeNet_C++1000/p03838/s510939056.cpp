#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long x, y, ans;
	cin >> x >> y;
	ans = abs(abs(y) - abs(x));
	if (x * y < 0)
		ans += 1;
	else
		if (x > y)
		{
			if (x == 0 || y == 0)
				ans += 1;
			else
				ans += 2;
		}
	cout << ans << endl;
	return 0;
}
