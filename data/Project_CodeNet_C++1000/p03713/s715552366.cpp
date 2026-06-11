#include <bits/stdc++.h>
using namespace std;
#define rep(i,n,x) for(ll i=(n);i<(x);++i)
#define rem(i,n,x) for(ll i=(n);i>=(x);--i)
#define SORT(x) sort(x.begin(),x.end())
#define all(x) x.begin(),x.end()
#define pb push_back
#define setp(x) setprecision(x)
using ll = long long;

int main() {
	int h, w; cin >> h >> w;

	ll ans = 1e10;
	rep(i, 1, h + 1) {
		ll x = max({ i * w, (h - i) * (w / 2),(h - i) * (w - (w / 2)) })
			- min({ i * w, (h - i) * (w / 2),(h - i) * (w - (w / 2)) });
		ll y = max({ i * w, (h - i) / 2 * w, ((h - i) - ((h - i) / 2)) * w })
			- min({ i * w, (h - i) / 2 * w, ((h - i) - ((h - i) / 2)) * w });
		ans = min({ ans, x, y });
	}
	rep(i, 1, w + 1) {
		ll x = max({ i * h, (w - i) * (h / 2), (w - i) * (h - (h / 2)) })
			- min({ i * h, (w - i) * (h / 2),(w - i) * (h - (h / 2)) });
		ll y = max({ i * h, (w - i) / 2 * h, ((w - i) - ((w - i) / 2)) * h })
			- min({ i * h, (w - i) / 2 * h, ((w - i) - ((w - i) / 2)) * h });
		ans = min({ ans, x, y });
	}

	cout << ans << endl;

	return 0;
}