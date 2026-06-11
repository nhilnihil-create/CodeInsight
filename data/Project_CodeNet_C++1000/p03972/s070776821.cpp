#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()

ll n, m, ans;
vector<pii> dt;

int main() {
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x;
		dt.pb({x, 0});
	}
	for (ll i = 0; i < m; i++) {
		ll x; cin >> x;
		dt.pb({x, 1});
	}
	sort(all(dt));
	n++, m++;
	for (pii p: dt) {
		if (p.S == 0) {
			ans += p.F * m;
			n--;
		} else {
			ans += p.F * n;
			m--;
		}
	}
	cout << ans;
}
