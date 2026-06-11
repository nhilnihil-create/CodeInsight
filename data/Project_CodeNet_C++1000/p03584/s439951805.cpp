#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

ll mod(ll a) {
	if (a > 0) return a % MOD;
	if (a % MOD == 0) return 0;
	ll x = -a / MOD + 1;
	a += x * MOD;
	return a % MOD;
}

template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(double x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
// int dx[4]    = {1, 0, -1, 0};
// int dy[4]    = {0, 1, 0, -1};
// ll pas[5001][5002];

int main() {
	IOS();
	ll n, k;
	cin >> n >> k;
	vector<ll> x, a(n), b(n);
	for (int i = 0; i < n; ++i) { cin >> a[i] >> b[i]; }
	x.push_back(k);
	ll tmp = 0;
	for (int i = 30; i >= 1; --i) {
		ll t = (1ll << i);
		if ((t & k) == t) {
			x.push_back(tmp + t - 1);
			tmp += t;
		}
	}
	int m  = x.size();
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		ll sum = 0;
		for (int j = 0; j < n; ++j) {
			bool ok = true;
			for (int k = 0; k < 30; ++k) {
				ll p = (1 << k) & a[j];
				ll q = (1 << k) & x[i];
				if (p > q) ok = false;
			}
			if (ok) sum += b[j];
		}
		ans = max(ans, sum);
	}
	dump(ans);
	return 0;
}