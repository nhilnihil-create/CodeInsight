#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 1000000007;
ll modsize;

ll modinv(ll a) {
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}

ll modpow(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) ans = ans * a%mod;
		a = a * a%mod;
		b >>= 1;
	}
	return ans;
}

int dp[5010][5010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	string s;
	cin >> n >> s;
	int k = s.size();
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] * 2 + dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n][k] * modinv(modpow(2, k)) % mod << endl;
}