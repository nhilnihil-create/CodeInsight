#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n; cin >> n;
	vector<ll> num(n, 0);
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		num[a]++;
	}
	
	const ll mod = 1000000007;
	ll ans = 1;
	bool can = true;
	if (n % 2 == 0) {
		for (ll i = 1; i <= n / 2; i++) {
			if (num[2 * i - 1] != 2) {
				can = false;
			}
		}
		if (can) {
			for (ll i = 1; i <= n / 2; i++) {
				ans *= 2;
				ans %= mod;
			}
		}
		else {
			ans = 0;
		}
	}
	else {
		if (num[0] == 1) {
			for (ll i = 1; i <= n / 2; i++) {
				if (num[2 * i] != 2) {
					can = false;
				}
			}
			if (can) {
				for (ll i = 1; i <= n / 2; i++) {
					ans *= 2;
					ans %= mod;
				}
			}
			else {
				ans = 0;
			}
		}
		else {
			ans = 0;
		}
	}
	cout << ans << endl;
	return 0;
}