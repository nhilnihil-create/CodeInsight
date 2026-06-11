#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, T; cin >> n >> T;
	vector<ll> t(n);
	for (ll i = 0; i < n; i++) {
		cin >> t[i];
	}
	ll ans = 0;
	for (ll i = 1; i <= n - 1; i++) {
		ans += min(T, t[i] - t[i - 1]);
	}
	ans += T;
	cout << ans << endl;
	return 0;
}