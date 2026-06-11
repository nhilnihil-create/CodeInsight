#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans, cnt;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll x, y;
	cin >> x >> y;

	if (abs(y) - abs(x) >= 0) {
		ans = abs(y) - abs(x);

		if (x < 0 && y < 0) {
			ans += 2;
		}
		else if (x >= 0 && y < 0) {
			ans += 1;
		}
		else if (x < 0 && y > 0) {
			ans += 1;
		}
	}
	else {
		ans = abs(x) - abs(y);

		if (x > 0 && y > 0) {
			ans += 2;
		}
		else if (x > 0 && y <= 0) {
			ans += 1;
		}
		else if (x < 0 && y > 0) {
			ans += 1;
		}
	}

	cout << ans << endl;

	return 0;
}