#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt += x == i;
		if(x != i) {
			ans += (cnt + 1) / 2;
			cnt = 0;
		}
	}
	ans += (cnt + 1) / 2;
	cout << ans << endl;
	return 0;
}