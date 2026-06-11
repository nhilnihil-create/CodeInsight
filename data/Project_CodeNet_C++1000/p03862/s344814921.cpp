#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; ll x; cin >> n >> x;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if(a[i - 1] + a[i] < x){}
		else if (x <= a[i - 1]) {
			ans += a[i];
			ans += a[i - 1] - x;
			a[i] = 0;
			a[i - 1] = x;
		}
		else {
			ll tmp = x - a[i - 1];
			ans += a[i] - tmp;
			a[i] = tmp;
		}
	}
	cout << ans << endl;
    return 0;
}