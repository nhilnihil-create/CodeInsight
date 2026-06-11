#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	int ans = 0, val;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		int x = i;
		while (x % 2 == 0) {
			cnt++;
			x /= 2;
		}
		// cout << cnt << '\n';
		if (cnt >= ans) {
			ans = cnt;
			val = i;
		}
	}
	cout << val;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	// cin >> tt;
	for (int i = 1; i <= tt; ++i) {
		solve();
	}

	return 0;
}
