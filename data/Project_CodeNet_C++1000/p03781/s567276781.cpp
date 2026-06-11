#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll x;
	cin >> x;
	ll l = 0, r = 2 * x;
	while (r - l > 1) {
		ll mid = l + (r - l) / 2;
		if (mid * (mid + 1) / 2 >= x) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}