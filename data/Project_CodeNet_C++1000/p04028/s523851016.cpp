#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;
typedef string::const_iterator State;
class ParseError {};

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

constexpr ll INF = 1e16;
constexpr ll INM = 114514;
constexpr ll MOD = 1e9 + 7;
constexpr ld EPS = 1e-12;

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
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

ll dp[5002][5002];

int main() {
	IOS();
	ll n, m;
	string s;
	cin >> n >> s;
	m = s.size();
	Fill(dp, 0);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j) dp[i][j] += 2 * dp[i - 1][j - 1];
			if (j == 0) dp[i][j] += dp[i - 1][j];
			dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}
	ll ans  = dp[n][m];
	ll inv2 = powm(2, MOD - 2, MOD);
	for (int i = 0; i < m; i++) {
		ans *= inv2;
		ans %= MOD;
	}
	dump(ans);
	return 0;
}