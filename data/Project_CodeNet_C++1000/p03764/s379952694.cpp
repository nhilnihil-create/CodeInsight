#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr ll MOD = 1e9+7;

ll x[100001], y[100001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < m; ++i) cin >> y[i];
	sort(x, x + n), sort(y, y + m);
	ll s = 0, a = 0;
	for (int i = 0; i < n; ++i) {
		s = (i * x[i] - a + s) % MOD, a = (x[i] + a) % MOD;
	}
	ll t = 0, b = 0;
	for (int i = 0; i < m; ++i) {
		t = (i * y[i] - b + t) % MOD, b = (y[i] + b) % MOD;
	}
	cout << s * t % MOD;
}