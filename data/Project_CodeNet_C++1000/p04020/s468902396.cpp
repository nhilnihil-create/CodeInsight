#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	long long ans;
	int a[n];
	ans = 0;
	rep(i, n) 
	{
		cin >> a[i];
		if (a[i] == 0) continue;
		if (i != 0)
			a[i] += a[i - 1];
		ans += a[i] / 2;
		a[i] %= 2;
	}
	cout << ans << endl;
	return 0;
}
