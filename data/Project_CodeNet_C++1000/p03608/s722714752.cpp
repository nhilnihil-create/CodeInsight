#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;//10^18
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll d[2134][2134];//コスト
void warshall_floyd(ll V) {
	for (int h = 1; h <= V; h++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				d[i][j] = min(d[i][j], d[i][h] + d[h][j]);
			}
		}
	}
}
ll ok[12345678], test[1000];
signed main() {
	for (int h = 0; h < 2134; h++) {
		for (int i = 0; i < 2134; i++) {
			d[h][i] = INF;
		}
	}
	ll n = 0, m, r, a = 0, b = 0, c = 0, cnt = 1, sum = 0, ans = INF;
	cin >> n >> m >> r; vector<ll> v;
	for (int h = 0; h < r; h++) { cin >> test[h]; }
	sort(test, test + r);
	for (int h = 0; h < m; h++) {
		cin >> a >> b >> c; d[a][b] = c; d[b][a] = c;
	}
	warshall_floyd(n);
	do {
		cnt = 0;
		for (int i = 1; i < r; i++) {
			cnt += d[test[i - 1]][test[i]];
		}
		ans = min(ans, cnt);
	} while (next_permutation(test, test + r));
	cout << ans << endl;
	return 0;
}