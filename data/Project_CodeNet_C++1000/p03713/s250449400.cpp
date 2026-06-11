#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll x, ll y, ll z) {
	ll maxV = max({ x,y,z });
	ll minV = min({ x,y,z });
	return maxV - minV;
}

int main() {

	ll h, w; cin >> h >> w;

	ll ans = 2147483647;
	for (ll y = 1; y <= h - 1; y++) {
		ll sa, sb, sc;
		sa = y * w;
		sb = w / 2 * (h - y);
		sc = (w - w / 2) * (h - y);
		ans = min(ans, func(sa, sb, sc));

		if (y == h - 1) continue;
		sa = y * w;
		sb = (h - y) / 2 * w;
		sc = (h - (y + (h - y) / 2)) * w;
		ans = min(ans, func(sa, sb, sc));
	}

	swap(h, w);
	for (ll y = 1; y <= h - 1; y++) {
		ll sa, sb, sc;
		sa = y * w;
		sb = w / 2 * (h - y);
		sc = (w - w / 2) * (h - y);
		ans = min(ans, func(sa, sb, sc));

		if (y == h - 1) continue;
		sa = y * w;
		sb = (h - y) / 2 * w;
		sc = (h - (y + (h - y) / 2)) * w;
		ans = min(ans, func(sa, sb, sc));
	}

	cout << ans << endl;
	return 0;
}