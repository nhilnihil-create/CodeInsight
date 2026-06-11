#define _USE_MATH_DEFINES
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
ll powm(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powm(a, b / 2, c);
		return (d * d) % c;
	} else
		return (a * powm(a, b - 1, c)) % c;
}
template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(double x, ll t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
// ll dx[4] = {1, 0, -1, 0};
// ll dy[4] = {0, 1, 0, -1};
// ll pas[5001][5002];

int main() {
	IOS();
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	vector<bool> use(m, true);
	ll ans = INF;
	for (int i = 0; i < m; ++i) {
		vector<ll> cnt(m, 0);
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (use[a[j][k]]) {
					cnt[a[j][k]]++;
					break;
				}
			}
		}
		ll num, size = 0;
		for (int i = 0; i < m; ++i) {
			if (size < cnt[i]) {
				size = cnt[i];
				num  = i;
			}
		}
		ans		 = min(ans, size);
		use[num] = false;
	}
	dump(ans);
	return 0;
}