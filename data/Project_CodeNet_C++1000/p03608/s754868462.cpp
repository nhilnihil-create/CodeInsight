#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge { ll to, cost; };

int main() {
	ll n, m, r;
	cin >> n >> m >> r;
	vector<ll> v(r);
	for (ll i = 0; i < r; ++i) {
		cin >> v[i];
		--v[i];
	}
	sort(v.begin(), v.end());
	vector<vector<ll>> g(n, vector<ll>(n, 1e15));
	for (ll i = 0; i < n; ++i)g[i][i] = 0;
	for (ll i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		g[a][b] = c;
		g[b][a] = c;
	}
	for (ll k = 0; k < n; ++k) {
		for (ll i = 0; i < n; ++i) {
			for (ll j = 0; j < n; ++j) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	ll ans = 1e18;
	do {
		ll preans = 0;
		for (ll i = 1; i < r; ++i) {
			preans += g[v[i - 1]][v[i]];
		}
		ans = min(ans, preans);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}
