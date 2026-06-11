
// Problem : D - Widespread
// Contest : AtCoder Regular Contest 075
// URL : https://atcoder.jp/contests/arc075/tasks/arc075_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n, a, b, h[N];

bool check(ll x) {
	if (x > LLONG_MAX / b) {
		return 1;
	}
	ll m = 0;
	for (int i = 1; i <= n; i++) {
		if (h[i] > x * b) {
			m += (h[i] - x * b) / (a - b) + !!((h[i] - x * b) % (a - b));
		}
	}
	return m <= x;
}

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	ll ans = -1;
	for (int i = 46; i >= 0; i--) {
		ans += 1ll << i;
		if (check(ans)) {
			ans -= 1ll << i;
		}
	}
	cout << ans + 1;
}
