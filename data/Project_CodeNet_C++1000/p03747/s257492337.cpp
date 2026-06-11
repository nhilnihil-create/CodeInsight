#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

ll x[100003], a[100003];
ll w[100003];

int main() {
	ll n; ll L, T; cin >> n >> L >> T;
	int t = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> x[i] >> w[i];
		if (w[i] == 2) w[i] = -1;
		a[i] = (x[i] + w[i] * T % L + L) % L;
		if (a[i] == a[0]) t = i;
	}
	ll f = a[0];
	sort(a, a + n);
	int b = lower_bound(a, a + n, f) - a;
	if (t != 0 && w[0] > w[t]) ++b;
	ll pos = 0;
	for (ll i = 1; i < n; ++i) {
		if (w[i] == w[0]) continue;
		if (w[0] == 1) {
			ll t = 2 * T;
			pos += x[i] - x[0] <= t ? 1 : 0;
			t = max(0LL, t - x[i] + x[0]);
			pos += t / L;
			pos %= n;
		}
		else {
			ll t = 2 * T;
			pos += L - x[i] + x[0] <= t ? 1 : 0;
			t = max(0LL, t - L + x[i] - x[0]);
			pos += t / L;
			pos %= n;
		}
	}
	if (w[0] == -1) pos = n - pos;
	for (ll i = 0; i < n; ++i) cout << a[(n - pos + b + i) % n] << endl;
	return 0;
}
