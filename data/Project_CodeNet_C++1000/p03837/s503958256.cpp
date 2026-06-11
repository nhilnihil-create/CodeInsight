#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5+5;
const int INF = 1e9+5;


int a[nax];
int b[nax];
int c[nax];
int main(){
	int n, m;
	
	cin >> n >> m;
	vector<vector<int>>dist(n, vector<int>(n, INF));
	for(int i=0; i<m; i++){
		cin >> a[i] >> b[i] >> c[i];
		a[i]--;
		b[i]--;
		dist[a[i]][b[i]] = c[i];
		dist[b[i]][a[i]] = c[i];
	}
	vector<vector<int>>g = dist;
	// using floyd warshall.
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

	int cnt = 0;
	for(int i = 0; i<m; i++){
		if(g[a[i]][b[i]] != dist[a[i]][b[i]]) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
