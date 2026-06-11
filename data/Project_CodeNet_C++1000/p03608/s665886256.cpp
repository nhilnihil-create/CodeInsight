#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, m, R;
	cin >> n >> m >> R;
	vector<int> r(R);
	rep(i, R) {
		cin >> r[i];
		r[i]--;
	}
	const int INF = 1001001001;
	vector<vector<int>> d(n, vector<int>(n, INF));
	rep(i, n) d[i][i] = 0;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		d[a][b] = c;
		d[b][a] = c;
	}
	
	for (int k = 0; k < n; k++){       // 経由する頂点
		for (int i = 0; i < n; i++) {    // 始点
			for (int j = 0; j < n; j++) {  // 終点
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	sort(all(r));
	int ans = INF;
	do {
		int now = 0;
		rep(i, R-1) {
			now += d[r[i]][r[i+1]];
		}
		ans = min(ans, now);
		// rep(i, R) cout << r[i] << " ";
		// cout << endl;
	} while (next_permutation(all(r)));
	cout << ans << endl;
	
	// rep(i, n) {
	// 	rep(j, n) {
	// 		cout << d[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	return 0;
}