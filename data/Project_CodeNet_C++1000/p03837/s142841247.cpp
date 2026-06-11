#include<bits/stdc++.h>
#define REP(i,b,e) for(int i=b; i<e; i++)

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int dist[n][n], a[m], b[m], c[m];
	REP(i, 0, n) REP(j, 0, n) dist[i][j] = 1e9;
	REP(i, 0, m){
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		a[i]--, b[i]--;
		dist[a[i]][b[i]] = c[i];
		dist[b[i]][a[i]] = c[i];
	}

	REP(k, 0, n) REP(i, 0, n) REP(j, 0, n) {
		dist[i][j] = std::min(dist[i][j], dist[i][k]+dist[k][j]);
	}

	int ans = 0;
	REP(i, 0, m){
		if(dist[a[i]][b[i]]!=c[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

