#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	ll n, p;
	cin >> n >> p;
	vl a(n);
	ll odd = 0, even = 0;
	rep(i, n) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}

	if (p == 0) {
		if (odd == 0) {
			out((ll)pow(2, n));
		}
		else {
			out((ll)pow(2, n - 1));
		}
	}
	else {
		if (odd > 0) {
			out((ll)pow(2, n - 1));
		}
		else {
			out(0);
		}
	}

	return 0;
}