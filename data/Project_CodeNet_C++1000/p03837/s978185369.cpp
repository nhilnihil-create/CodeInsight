#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 2e9;

ll dist[105][105];

void warchall_floyd(int N){
    rep(k,N)rep(i,N){
        if(dist[i][k] == INF) continue;
        rep(j,N){
            if(dist[k][j] == INF) continue;
	        chmin(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	rep(i,n){
		rep(j,n) dist[i][j] = INF;
		dist[i][i] = 0;
	}
	vector<int> a(m), b(m), c(m);
	rep(i,m){
		cin >> a[i] >> b[i] >> c[i];
		--a[i]; --b[i];
		dist[a[i]][b[i]] = c[i];
		dist[b[i]][a[i]] = c[i];
	}
	warchall_floyd(n);
	int ans = 0;
	rep(i,m){
		if(dist[a[i]][b[i]] == c[i]) continue;
		if(dist[b[i]][a[i]] == c[i]) continue;
		++ans;
	}
	cout << ans << endl;
	return 0;
}