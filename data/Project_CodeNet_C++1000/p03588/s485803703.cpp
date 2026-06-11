#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, maxi, ans;
	cin >> n;
	maxi = 0;
	rep(i, n)
	{
		int a, b;
		cin >> a >> b;
		if (a > maxi)
		{
			maxi = a;
			ans = a + b;
		}
	}
	cout << ans << endl;
	return 0;
}
