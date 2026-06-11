#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N, M; cin >> N >> M;
    vector<vector<ll>> dist(N,vector<ll>(N,INF));
    rep(i,N) dist[i][i] = 0;

    vector<ll> a(M), b(M), c(M);
    rep(i,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }

    rep(k,N){
        rep(i,N){
            rep(j,N){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i,M){
        if (c[i] > dist[a[i]][b[i]]) ans++;
    }
    cout << ans << endl;
}