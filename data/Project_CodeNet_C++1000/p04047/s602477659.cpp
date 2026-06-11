#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans;
	cin >> n;
	vector<int> l(2 * n);
	rep(i, 2 * n) cin >> l[i];
	sort(l.begin(), l.end());
	ans = 0;
	for(int i = 0; i < 2 * n; i+=2)
	{
		ans += l[i];
	}
	cout << ans << endl;
	return 0;
}
