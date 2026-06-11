#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll n,x;
	cin >> n >> x;
	vector<ll> a(n),b(n);
	rep(i,n) cin >> a[i];
	b[0] = min(x,a[0]);
	rep(i,n-1) b[i+1] = min(a[i+1],x-b[i]);
	ll ans = 0;
	rep(i,n) ans += a[i] - b[i];
	cout << ans << endl;
	return 0;
}
