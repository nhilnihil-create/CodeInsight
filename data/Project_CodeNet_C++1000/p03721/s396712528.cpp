#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, k; cin >> n >> k;
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		mp[a] += b;
	}
	ll cnt = 0;
	ll ans;
	for (auto u : mp) {
		cnt += u.second;
		if (k <= cnt) {
			ans = u.first;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}