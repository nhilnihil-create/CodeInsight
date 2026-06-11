#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, a, b; cin >> n >> a >> b;
	vector<ll> x(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
	}
	ll ans = 0;
	vector<ll> diff(n - 1);
	for (ll i = 0; i < n - 1; i++) {
		diff[i] = x[i + 1] - x[i];
		ans += min(a * diff[i], b);
	}
	cout << ans << endl;
	return 0;
}