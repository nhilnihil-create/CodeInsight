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
const ll MAX_N = 100010;
 
int main() {
    ll n, m;
    cin >> n >> m;
 
    vl a(m), b(m), c(m);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;  b[i]--;
        c[i] *= -1;
    }
    
    // ベルマンフォード法。計算量はO(V*E)
    vl dist(n, INF);  // dist[v] : 頂点svから頂点vへの最短距離
    const ll sv = 0;  // 始点となる頂点。デフォルトでは0
    dist[sv] = 0;
    rep(loop, n-1) {
        rep(i, m) {
            if(dist[a[i]] == INF) {
                continue;
            }
            if(dist[b[i]] > dist[a[i]] + c[i]) {
                dist[b[i]] = dist[a[i]] + c[i];
            }
        }
    }
 
    vl negativeCycle(n);  // negativeCycle[v] : 頂点vへのパスに負閉路が含まれるとき1
    rep(loop, n) {
        rep(i, m) {
            if(dist[a[i]] == INF) {
                continue;
            }
            if(dist[b[i]] > dist[a[i]] + c[i]) {
                dist[b[i]] = dist[a[i]] + c[i];
                negativeCycle[b[i]] = 1;
            }
            if(negativeCycle[a[i]]) {
                negativeCycle[b[i]] = 1;
            }
        }
    }
 
    if(negativeCycle[n-1]) {
        out("inf");
    }
    else {
        out(-dist[n-1]);   
    }
 
    re0;
}