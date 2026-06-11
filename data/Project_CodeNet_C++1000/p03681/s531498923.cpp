#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	const ll mod = 1000000007;
	if (n < m) swap(n, m); // m <= n  
	if (2 <= n - m) {
		cout << 0 << endl;
	}
	else {
		ll ans = 1;
		if (n == m) {
			ll cnt = n;
			while (cnt--) {
				ans *= (cnt + 1);
				ans %= mod;
				ans *= (cnt + 1);
				ans %= mod;
			}
			ans *= 2;
			ans %= mod;
			cout << ans << endl;
		}
		else {
			while (n--) {
				ans *= (n + 1);
				ans %= mod;
			}
			while (m--) {
				ans *= (m + 1);
				ans %= mod;
			}
			cout << ans << endl;
		}
	}
	return 0;
}