#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

vector<vector<pair<int, int>>> g;
vector<ll> dist;

void dfs ( int u, ll d) {
    if ( dist[u] >= 0 ) return;
    dist[u] = d;
    for ( auto p : g[u] ) {
        dfs(p.first, d + p.second);
    }
}

int main(){
    int n;
    cin >> n;
    g.resize(n+1);
    rep(i, n-1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    int q, k;
    cin >> q >> k;
    dist.assign(n + 1, -1);
    dfs(k, 0);
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        ll ans = dist[x] + dist[y];
        cout << ans << endl;
    }
    return 0;
}
