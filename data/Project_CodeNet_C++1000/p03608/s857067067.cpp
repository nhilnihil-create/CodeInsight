#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)

constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

ll g[202][202];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, r; cin >> n >> m >> r;
	vector<int> a(r); rep(i, 0, r) cin >> a[i], --a[i];
	rep(i, 0, n) rep(j, 0, n) if (i != j) g[i][j] = INF;

	rep(i, 0, m) {
		ll a, b, c; cin >> a >> b >> c;
		--a, --b;
		g[a][b] = c;
		g[b][a] = c;
	}
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	sort(a.begin(), a.end());
	ll ans = INF;
	do {
		ll tmp = 0;
		rep(i, 0, r - 1)
			tmp += g[a[i + 1]][a[i]];
		ans = min(ans, tmp);
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << endl;
	return 0;
}
