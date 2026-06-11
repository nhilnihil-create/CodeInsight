#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, j;
	long long ans, sum;

	cin >> n;
	vector<int> a(3 * n);
	rep(i, 3 * n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	ans = sum = 0;
	for(int i = n; i < n + n; i++)
	{
		ans += a[i];
	}
	j = 1;
	rep(i, n)
	{
		sum += a[j];
		j+=2;
	}
	ans = max(ans, sum);
	cout << ans << endl;
	return 0;
}
