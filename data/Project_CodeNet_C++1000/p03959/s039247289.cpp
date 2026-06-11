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

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
// int dx[4]    = {1, 0, -1, 0};
// int dy[4]    = {0, 1, 0, -1};
// ll pas[5001][5002];

bool unko[114514] = {};
#define UNKO                                                                   \
	cout << 0 << endl;                                                         \
	return 0;

int main() {
	IOS();
	ll n;
	cin >> n;
	vector<ll> a(n), t(n);
	for (int i = 0; i < n; ++i) { cin >> t[i]; }
	for (int i = 0; i < n; ++i) { cin >> a[i]; }
	if (a[0] != t[n - 1]) { UNKO }
	unko[0] = unko[n - 1] = true;
	for (int i = 1; i < n; ++i) {
		if (t[i] > t[i - 1]) {
			unko[i] = true;
			if (t[i] > a[i]) { UNKO }
		} else if (t[i] < t[i - 1]) {
			UNKO
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] > a[i + 1]) {
			unko[i] = true;
			if (a[i] > t[i]) { UNKO }
		} else if (a[i] < a[i + 1]) {
			UNKO
		}
	}
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		if (unko[i]) continue;
		ans *= min(a[i], t[i]);
		ans %= MOD;
	}
	cout << ans << endl;

	return 0;
}