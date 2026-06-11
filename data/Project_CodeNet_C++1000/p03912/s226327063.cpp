#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-12;

template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
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
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

//ll dx[4] = {1, 0, -1, 0};
//ll dy[4] = {0, 1, 0, -1};

ll g[114514]   = {};
ll cnt[114514] = {};
int main() {
	IOS();
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		g[a[i] % m]++;
		mp[a[i]]++;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cnt[it->first % m] += it->second / 2;
	}
	ll ans = g[0] / 2;
	for (int i = 1; i * 2 < m; i++) {
		ll tmp = min(g[i], g[m - i]);
		ans += tmp;
		if (g[i] >= g[m - i]) {
			ans += min(cnt[i], (g[i] - tmp) / 2);
		} else {
			ans += min(cnt[m - i], (g[m - i] - tmp) / 2);
		}
	}
	if (m % 2 == 0) ans += g[m / 2] / 2;
	dump(ans);
	return 0;
}