#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 2e9;

ll dist[505][505];

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
    int n, m, R;
    cin >> n >> m >> R;
    rep(i,n){
        rep(j,n) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    vector<int> r(R);
    rep(i,R){
        cin >> r[i];
        r[i]--;
    }
    int a, b;
    ll c;
    rep(i,m){
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    warchall_floyd(n);
    vector<int> v(R);
    rep(i,R) v[i] = i;
    ll ans = INF;
    do{
		ll path = 0;
        rep(i,R-1){
            path += dist[r[v[i]]][r[v[i+1]]];
        }
        chmin(ans, path);
	} while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}