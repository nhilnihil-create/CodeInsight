#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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

int main() {
    ll n, m;
    cin >> n >> m;    
    
    vvl G(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    // BFS。計算量はO(V+E)
    vl dist(n, -1);  // dist[v] : 頂点svから頂点vへの最短距離(-1のとき未訪問)
    queue<ll> Q;
    const ll sv = 0;  // BFSを始める頂点
    dist[sv] = 0;
    Q.push(sv);
    while(!Q.empty()) {
        ll v = Q.front();  Q.pop();
        for(ll u : G[v]) {
            if(dist[u] == -1) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }

    if(dist[n-1] == 2) {
        out("POSSIBLE");
    }
    else {
        out("IMPOSSIBLE");
    }

    re0;
}