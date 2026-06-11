#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;
const ll MOD = 1000000007;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;
	cin >> n >> a >> b;

	vector<ll> x(n);
	for (auto &v : x) {
		cin >> v;
	}

	vector<ll> dp(n);
	for (int i = 1; i < n; i++) {
		dp[i] += dp[i - 1] + min(a * (x[i] - x[i - 1]), b);
	}

	cout << dp[n - 1] << endl;
	return 0;
}
