#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll n,t_max;
	cin >> n >> t_max;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	ll ans = 0;
	for(int i=1;i<n;i++) {
		ans += min(t_max, t[i] - t[i-1]);
	}
	ans += t_max;
	cout << ans << endl;
	return 0;
}
