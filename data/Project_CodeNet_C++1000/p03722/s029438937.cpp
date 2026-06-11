#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

struct Edge {
  ll to, cost;
  Edge(ll to, ll cost) : to(to), cost(cost) {}
};

vector<vector<Edge>> g;

const ll INF = 1e18;
vector<bool> isCycle;
vector<ll> bellman_ford(vector<vector<Edge>>& graph, ll s) {
  ll n = SZ(graph);
  vector<ll> dist(n, INF);
  dist[s] = 0;
  REP(i, n) {
    REP(v, n) {
      if (dist[v] == INF) {
        continue;
      }
      REP(k, SZ(graph[v])) {
        Edge e = graph[v][k];
        ll tmp = dist[v] + e.cost;
        if (dist[e.to] <= tmp) {
          continue;
        }
        dist[e.to] = tmp;
        if (i == n - 1) {
          isCycle[v] = true;
        }
      }
    }
  }
  return dist;
}

bool seen[1010];
ll n, m;

bool dfs(ll cv, ll dst) {
  if (cv == dst) {
    return true;
  }
  bool res = false;
  for (Edge e : g[cv]) {
    ll to = e.to;
    if (seen[to]) {
      continue;
    }
    seen[to] = true;
    res |= dfs(to, dst);
  }

  return res;
}

bool canReach(ll s, ll t) {
  REP(i, n) { seen[i] = false; }
  return dfs(s, t);
}

int main() {
  cin >> n >> m;
  g = vector<vector<Edge>>(n);
  isCycle = vector<bool>(n, false);
  REP(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back(Edge(b, -c));
  }
  vector<ll> dist = bellman_ford(g, 0);
  REP(i, n) {
    if (isCycle[i] && canReach(0, i) && canReach(i, n - 1)) {
      cout << "inf"
           << "\n";
      return 0;
    }
  }
  cout << -dist[n - 1] << "\n";
}
