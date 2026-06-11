#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int d[205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, R;
	cin >> n >> m >> R;
	vector<int> r(R);
	rep(i, R) cin >> r[i], r[i]--;
	sort(all(r));
	rep(i, n)rep(j, n) d[i][j] = inf;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		d[a][b] = c;
		d[b][a] = c;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = inf;
	do {
		int tmp = 0;
		rep(i, R - 1) {
			tmp += d[r[i]][r[i + 1]];
		}
		ans = min(ans, tmp);
	} while (next_permutation(all(r)));
	cout << ans << endl;
	return 0;
}
