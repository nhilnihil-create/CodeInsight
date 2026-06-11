#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll, ll>;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18;
ll f(ll a, ll c, ll d) {
	ll p = a / c, q = a / d, r = a / (c / __gcd(c, d) * d);
	return a - (p + q - r);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];
	ll now = max(1LL, a[0]), ans = (now == a[0] ? 0 : 1 - a[0]);
	ll b[n];
	b[0] = now;
	rep(i, n - 1) {
		now += a[i + 1];
		if (now * b[i] < 0)
			b[i + 1] = now;
		else if (b[i] > 0) {
			now = -1, b[i + 1] = now;
			ans += abs(b[i] + 1 + a[i + 1]);
		} else {
			now = 1, b[i + 1] = now;
			ans += abs(1 - b[i] - a[i + 1]);
		}
	}
	now = min(-1LL, a[0]);
	ll ans1 = (now == a[0] ? 0 : 1 + a[0]);
	b[0] = now;
	rep(i, n - 1) {
		now += a[i + 1];
		if (now * b[i] < 0)
			b[i + 1] = now;
		else if (b[i] > 0) {
			now = -1, b[i + 1] = now;
			ans1 += abs(b[i] + 1 + a[i + 1]);
		} else {
			now = 1, b[i + 1] = now;
			ans1 += abs(1 - b[i] - a[i + 1]);
		}
	}
	cout << min(ans, ans1) << endl;
	return 0;
}
