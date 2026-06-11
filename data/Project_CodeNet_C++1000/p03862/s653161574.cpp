#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
	int n; ll x; cin >> n >> x;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll t = min(a[i], max(a[i - 1] + a[i] - x, 0ll));
		a[i] -= t; ans += t;
	}
	for (int i = n - 2; i >= 0; i--) {
		ll t = min(a[i], max(a[i + 1] + a[i] - x, 0ll));
		a[i] -= t; ans += t;
	}
	cout << ans << '\n';
}
