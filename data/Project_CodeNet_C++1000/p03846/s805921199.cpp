#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll mod = 1000000007;
	ll n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	sort(a.begin(), a.end());
	if (n % 2 == 1) { // odd
		bool can = true;
		if (a[0] != 0) can = false;
		for (int i = 1; i <=  (n - 1)/2; i++) {
			if (!(a[2 * (i- 1) + 1] == i * 2 && a[2 * (i - 1) + 2] == i * 2)) can = false;
		}
		ll cnt = (n - 1) / 2;
		ll ans = 1;
		while (cnt--) {
			ans *= 2;
			ans %= mod;
		}
		if (can) cout << ans << endl;
		else cout << 0 << endl;
	}
	else { // even
		bool can = true;
		for (int i = 0; i < n / 2; i++) {
			if (!(a[2 * i] == 2 * (i + 1) - 1 && a[2 * i + 1] == 2 * (i + 1) - 1)) can = false;
		}
		ll cnt = n / 2;
		ll ans = 1;
		while (cnt--) {
			ans *= 2;
			ans %= mod;
		}
		if (can) cout << ans << endl;
		else cout << 0 << endl;
	}
	return 0;
}