#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> rt(r);
	rep(i,r) {
		cin >> rt[i];
		rt[i]--;
	}
	vector<vector<ll>> d(n, vector<ll>(n, INF));
	rep(i,m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		d[a][b] = c;
		d[b][a] = c;
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	ll ans = LINF;
	sort(ALL(rt));
	do {
		ll sum = 0;
		for (int i = 1; i < r; i++) {
			int x = rt[i-1];
			int y = rt[i];
			sum += d[x][y];
		}
		ans = min(ans, sum);
	} while (next_permutation(ALL(rt)));
	cout << ans << endl;
}