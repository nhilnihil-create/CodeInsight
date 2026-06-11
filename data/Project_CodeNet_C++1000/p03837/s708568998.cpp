#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m), c(m);
	rep(i,m) cin >> a[i] >> b[i] >> c[i];
	vector<vector<int>> dist(n, vector<int>(n,INF));
	rep(i,n) dist[i][i] = 0;
	rep(i,m) {
		dist[a[i]-1][b[i]-1] = c[i];
		dist[b[i]-1][a[i]-1] = c[i];
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	int ans = 0;
	rep(i,m) {
		if (dist[a[i]-1][b[i]-1] != c[i]) ans++;
	}
	cout << ans << endl;
}