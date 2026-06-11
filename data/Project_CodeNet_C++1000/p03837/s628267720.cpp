#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int INF = 1e8;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int dist[n][n], used[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
			used[i][j] = -1;
		}
	}
	int c[m];
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y >> c[i];
		--x; --y;
		if (dist[x][y] >= c[i]) {
			dist[x][y] = dist[y][x] = c[i];
			used[x][y] = used[y][x] = i;
		}
	}
	
	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			if (i == k) continue;
			for (int j=0; j<n; j++) {
				if (i == j || j == k) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					used[i][j] = used[i][k];
				}
			}
		}
	}
	
	bool vis[m];
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j) continue;
			if (!vis[used[i][j]]) cnt++;
			vis[used[i][j]] = true;
		}
	}
	cout << m - cnt;
}