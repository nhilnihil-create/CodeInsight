#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 2e9;

ll dist[505][505];
ll dist2[505][505];

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
    int v, e;
    cin >> v >> e;
    rep(i,v){
        rep(j,v){
			dist[i][j] = INF;
			dist2[i][j] = INF;
		}
        dist[i][i] = 0;
		dist2[i][i] = 0;
    }
    rep(i,e){
        int s, t, d;
        cin >> s >> t >> d;
		--s; --t;
        dist[s][t] = d;
		dist[t][s] = d;
		dist2[s][t] = d;
		dist2[t][s] = d;
    }
    warchall_floyd(v);
	int ans = 0;
	rep(i,v){
		for(int j = i+1; j < v; ++j){
			if(dist2[i][j] != INF && dist[i][j] != dist2[i][j]) ++ans;
		}
	}
	cout << ans << endl;
    return 0;
}