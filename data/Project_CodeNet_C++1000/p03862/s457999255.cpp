#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = 0;
	rep(i, n) {
		if(a[i] > x) {
			ans += a[i] - x;
			a[i] = x;
		}
	}
	rep(i, n-1) {
		if(a[i]+a[i+1] > x) {
			ll dif = a[i] + a[i+1] - x;
			a[i+1] -= dif;
			ans += dif;
		}
	}
	cout << ans << endl;
	return 0;
}