#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, x; cin >> n >> x;
	vector<ll> a(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll ans = 0;
	if (x < a[0]) {
		ans += a[0] - x;
		a[0] = x;
	}
	for (ll i = 1; i < n; i++) {
		ll a_now = a[i];
		ll a_prev = a[i - 1];
		ll diff = a_now + a_prev - x;
		if (x < a_now + a_prev) {
			a[i] -= diff;
			ans += diff;
		}
	}
	cout << ans << endl;
	return 0;
}