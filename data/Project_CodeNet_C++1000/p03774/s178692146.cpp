#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int a[n], b[n], c[m], d[m];
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, m) cin >> c[i] >> d[i];
	rep(i, n) {
		int num = -1, dist = 1e9;
		rep(j, m) {
			int p = abs(a[i] - c[j]) + abs(b[i] - d[j]);
			if (p < dist) { dist = p, num = j + 1; }
		}
		cout << num << endl;
	}
	return 0;
}