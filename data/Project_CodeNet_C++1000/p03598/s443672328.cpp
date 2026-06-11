#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += min(2 * abs(x[i] - 0), 2 * abs(k - x[i]));
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	// cin >> tt;
	for (int i = 1; i <= tt; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
