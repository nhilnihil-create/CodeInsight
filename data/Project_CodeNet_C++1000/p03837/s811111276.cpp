#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//using pr = pair<ll, ll>;
using graph = vector<vector<ll>>;
#define rep(n, i) for(ll i = 0; i < n; ++i)

const ll INF = 1e18;

void wf(const graph& g, vector<vector<ll>>& d) {
  ll v = (ll)g.size();
  rep(v, k) {
    rep(v, i) {
      rep(v, j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

void solve(void){
  ll v, e; cin >> v >> e;
  graph g(v, vector<ll>(v, -1));
  vector<vector<ll>> dist(v, vector<ll>(v, INF));

  rep(e, i) {
    ll ta, tb, tc; cin >> ta >> tb >> tc;
    --ta, --tb;
    g[ta][tb] = tc;
    g[tb][ta] = tc;
    dist[ta][tb] = tc;
    dist[tb][ta] = tc;
  }

  rep(v, i) {
    rep(v, j) {
      if (i == j) dist[i][j] = 0;
    }
  }

  wf(g, dist);

  ll res = 0;
  rep(v, i) {
    for(ll j = i + 1; j < v; ++j) {
      if (g[i][j] > 0 && (g[i][j] > dist[i][j])) ++res;
    }
  }

  cout << res << endl;
}

int main(void) {
  solve();
  return 0;
}
