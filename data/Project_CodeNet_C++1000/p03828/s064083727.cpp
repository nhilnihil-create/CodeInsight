#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i < b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const long double PI = acos(-1);

std::map<ll, ll> prime_factor(ll n) {
	std::map<ll, ll> res;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	ll n;
	cin >> n;

	vector<ll> e(n + 1, 0);
	for (ll i = 2; i <= n; i++) {
		auto primefactor = prime_factor(i);
		for (auto pf : primefactor) {
			e[pf.first] += pf.second;
		}
	}

	ll ans = 1;
	for (ll i = 2; i <= n; i++) {
		ans *= e[i] + 1;
		ans %= mod;
	}

	out(ans);

	return 0;
}