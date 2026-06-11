#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll c, ll x) {
	if (c < 0) c = 0;
	ll res = c / x;
	return res;
}

int main() {
	ll a, b, x; cin >> a >> b >> x;
	ll ans = 0;
	if (a == 0) {
		a++;
		ans += 1;
	}
	ans += func(b, x) - func(a - 1, x);
	cout << ans << endl;
	return 0;
}