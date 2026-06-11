#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		mp[a]++;
	}
	ll ans = 0;
	for (auto u : mp) {
		if (u.second % 2 != 0) ans++;
	}
	cout << ans << endl;
	return 0;
}