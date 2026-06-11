#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : abs(x); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for (auto &v : a) {
		cin >> v;
	}

	sort(begin(a), end(a));

	ll ans = n, score = 0;
	for (ll i = n - 1; i >= 0; i--) {
		if (score + a[i] < k) {
			score += a[i];
			continue;
		}

		ans = min(ans, i);
	}

	cout << ans << endl;
	return 0;
}
