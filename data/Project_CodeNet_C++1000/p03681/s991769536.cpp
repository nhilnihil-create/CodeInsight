#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	const ll mod = 1000000007;
	ll n, m; cin >> n >> m;
	if (n < m) {
		swap(n, m);
	}
	if (2 <= n - m) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	if (n - m == 1) {
		for (ll i = 0; i < n; i++) {
			ans *= (i + 1);
			ans %= mod;
		}
		for (ll i = 0; i < m; i++) {
			ans *= (i + 1);
			ans %= mod;
		}
	}
	else { // n = m
		ans *= 2;
		for (ll i = 0; i < n; i++) {
			ans *= (i + 1);
			ans %= mod;
		}
		for (ll i = 0; i < m; i++) {
			ans *= (i + 1);
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}