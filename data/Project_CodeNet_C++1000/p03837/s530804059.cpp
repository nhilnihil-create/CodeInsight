#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1e9;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m), c(m);
	vector<vector<int>> dist(n, vector<int>(n,INF));
	rep(i,m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		dist[a[i]][b[i]] = c[i];
		dist[b[i]][a[i]] = c[i];
	}
	rep(k,n) rep(i,n) rep(j,n) {
		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	}
	int ans = 0;
	rep(i,m) {
		if (dist[a[i]][b[i]] != c[i]) ans++;
	}
	cout << ans << endl;
}