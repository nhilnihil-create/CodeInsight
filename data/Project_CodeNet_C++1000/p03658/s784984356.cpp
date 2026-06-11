#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	ll n, k;
	ll l[60];
	cin >> n >> k;
	rep(i, n) cin >> l[i];
	sort(l,l+n, greater<ll>());
	ll ans = 0;
	rep(i, k) ans += l[i];
	cout << ans << endl;
}
