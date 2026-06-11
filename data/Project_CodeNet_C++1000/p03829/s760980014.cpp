#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> x(n);
	rep(i,n) cin >> x[i];

	ll ans = 0;
	rep(i,n-1) {
		ll d = x[i+1] - x[i];
		ans += min(a*d, b);
	}

	cout << ans << endl;

	return 0;
}
