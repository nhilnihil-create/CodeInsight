#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

signed main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	// 右の方が大きいところがk箇所
	for (int k = 0; k < n; ++k) {
		ll low = (ll)c * k - (ll)d * (n - 1 - k);
		ll up = (ll)d * k - (ll)c * (n - 1 - k);
		if (low <= (b - a) && (b - a) <= up) {
			cout << "YES" << endl;
			exit(0);
		}
	}

	cout << "NO" << endl;

	return 0;
}