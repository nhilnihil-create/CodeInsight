#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll divplus(ll a, ll b) {
	return (a+b-1)/b;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> t(n), a(n);
	rep(i,n) cin >> t[i] >> a[i];
	ll ht,ha;  // 得票数の最小値
	ht = t[0], ha = a[0];
	for (int i=1;i<n;i++) {
		ll bai = max(divplus(ht,t[i]), divplus(ha,a[i]));
		ht = bai * t[i], ha = bai * a[i];
	}

	cout << ht + ha << endl;
	return 0;
}
