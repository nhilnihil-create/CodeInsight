#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, x; cin >> n >> x;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	if (x < a[0]) {
		ans += a[0] - x;
		a[0] = x;		
	}
	for (int i = 1; i < n; i++) {
		ll a_next = a[i];
		ll a_now = a[i - 1];
		if (a_now + a_next < x) {}
		else { // x <= a_now + a_next 
			ll diff = a_now + a_next - x;
			a[i] -= diff;
			ans += diff;
		}		
	}
	cout << ans << endl;
	return 0;
}