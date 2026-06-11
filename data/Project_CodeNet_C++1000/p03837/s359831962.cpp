#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, ans = 0;
	const int MAX = 1 << 29;
	cin >> n >> m;
	int dist[n][n];
	int a[m], b[m], c[m];
	for (size_t i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			dist[i][j] = MAX;
		}
		dist[i][i] = 0;
	}

	for(int i=0; i < m; i++) {
		dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
		dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
	}

	for(int k=0; k < n; k++) {
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for(int i=0; i < m; i++) {
		if(dist[a[i]][b[i]] < c[i])
			ans++;
	}
	cout << ans << endl;
}
