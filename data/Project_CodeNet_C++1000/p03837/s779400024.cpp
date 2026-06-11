#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif


int main() {
    ll n, m;
    cin >> n >> m;

    // 頂点 a[i], b[i]
    // 辺の長さ c[i]
    // 最短距離 dist[i][j]
    vll a(m), b(m), c(m);
    vvll dist(n, vll(n));

    // 頂点a[i]とb[i]の距離がc[i]
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }

    // 最短距離の初期化
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // 辺がある場合は更新
    for(int i = 0; i < m; i++) {
        chmin(dist[a[i]][b[i]], c[i]);
        chmin(dist[b[i]][a[i]], c[i]);
    }

    // ワーシャルフロイド法
    for(int k = 0; k < n; k++) { // 経由する頂点
        for(int i = 0; i < n; i++){ // スタート
            for(int j = 0; j < n; j++){ // ゴール
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vvll cnt(n, vll(n, 0));
    rep(i, n) rep(j, n) rep(k, m) {
        if(dist[i][a[k]] + c[k] + dist[j][b[k]] == dist[i][j]) cnt[a[k]][b[k]] = cnt[b[k]][a[k]] = 1;
        if(dist[i][b[k]] + c[k] + dist[j][a[k]] == dist[i][j]) cnt[a[k]][b[k]] = cnt[b[k]][a[k]] = 1;
    }
    ll ans = m;
    rep(i, n) for(ll j = i+1; j < n; j++) if(cnt[i][j] == 1) ans--;
    cout << ans << endl;
}