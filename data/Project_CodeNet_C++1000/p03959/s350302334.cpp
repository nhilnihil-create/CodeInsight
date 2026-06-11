#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<int> c(n), d(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) c[i] = a[i];
		else {
			if (a[i] > a[i -1]) c[i] = a[i];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) d[i] = b[i];
		else {
			if (b[i] > b[i + 1]) d[i] = b[i];
		}
	}
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (c[i] && d[i]) {
			if (c[i] != d[i]) ans = 0;
		}
		if (c[i]) {
			if (b[i] < c[i]) ans = 0;
		}
		if (d[i]) {
			if (a[i] < d[i]) ans = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (c[i] || d[i]) continue;
		ans *= min(a[i], b[i]);
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}
