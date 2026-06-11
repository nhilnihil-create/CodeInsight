#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mmm(ll a, ll b, ll c) {
	ll mi = min({a, b, c});
	ll ma = max({a, b, c});
	return ma - mi;
}

ll solv(ll H, ll W) {
	ll ans = W*H, s1, s2, s3;
	for(ll i=1; i<H-1; i++) {
		ll x = H-i;
		s1 = W * i;
		s2 = W * (x/2);
		s3 = W * (x/2 + x%2);
		ans = min(ans, mmm(s1,s2,s3));
	}
	for(ll i=1; i<H; i++) {
		ll x = H-i;
		s1 = i * W;
		s2 = x * (W/2);
		s3 = x * (W/2 + W%2);
		ans = min(ans, mmm(s1,s2,s3));
	}
	return ans;
}

int main() {

	int H, W;
	cin >> H >> W;

	cout << min(solv(H,W), solv(W,H)) << endl;

}