#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_V = 110;

int main() {
    ll n, m;
    cin >> n >> m;

    vvl dist(MAX_V, vl(MAX_V));  // dist[u][v] : 頂点uと頂点vの最短距離
    rep(i, n) {
        rep(j, n) {
            if(i != j) {
                dist[i][j] = INF;
            }
        }
    }
    
    vvl G(n, vl(n));  // G[i][j] : 頂点iと頂点jを結ぶ辺の距離
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;  b--;
        G[a][b] = G[b][a] = c;
        if(dist[a][b] > c) {
            dist[a][b] = dist[b][a] = c;
        }
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = 0;
    rep(u, n-1) {
        exrep(v, u+1, n-1) {
            rep(w, n) {
                if(u != w && v != w && dist[u][w] + dist[w][v] < G[u][v]) {
                    ans++;
                    break;
                }
            }
        }
    }
    
    out(ans);
    re0;
}