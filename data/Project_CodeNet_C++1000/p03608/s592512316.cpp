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
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
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
const ll MAX_V = 410;

int main() {
    ll n, m, R;
    cin >> n >> m >> R;

    vl r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }

    vvl dist(MAX_V, vl(MAX_V));  // dist[v][u] : 頂点vと頂点uの最短距離
    rep(v, n) {
        rep(u, n) {
            if(v != u) {
                dist[v][u] = INF;
            }
        }
    }
    
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;  b--;
        if(dist[a][b] > c) {
            dist[a][b] = dist[b][a] = c;
        }
    }
    
    // ワーシャルフロイド法。計算量はO(V^3)
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vl perm(R);
    rep(i, R) {
        perm[i] = i;
    }

    ll ans = INF;
    do {
        ll now = 0;
        rep(i, R-1) {
            now += dist[r[perm[i]]][r[perm[i+1]]];
        }
        chmin(ans, now);
    } while(next_permutation(all(perm)));
    
    out(ans);
    re0;
}