#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

struct edge {
  ll to;
  ll cost;
};
struct graph {
  ll V;
  vector<vector<edge>> G;
  vector<ll> d;

  graph(ll n) {
    V = n;
    G = vector<vector<edge>>(V);
    d = vector<ll>(V, INF);
  }

  void add_edge(ll s, ll t, ll cost) {
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s) {
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0, s));
    while (!q.empty()) {
      P p = q.top();
      q.pop();
      ll v = p.second;
      if (d[v] < p.first) continue;
      for (auto e : G[v]) {
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          q.push(P(d[e.to], e.to));
        }
      }
    }
  }
};

int main() {
  ll n, a, b, c, q, k, x, y;
  cin >> n;
  graph g(n);
  rep(i, n - 1) {
    cin >> a >> b >> c;
    a--, b--;
    g.add_edge(a, b, c);
    g.add_edge(b, a, c);
  }

  cin >> q >> k;
  k--;
  g.dijkstra(k);
  rep(i, q) {
    cin >> x >> y;
    x--, y--;
    cout << g.d[x] + g.d[y] << endl;
  }
  return 0;
}
