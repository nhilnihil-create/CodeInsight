#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

Graph tips;
vi vertex;

void dfs(const Graph &G, const int &rad, const int &center, int d, int v, int p) {
  for (auto nv : G[v]) {
    if (nv == p) continue;

    ++vertex[center];

    if (d+1 == rad) {
      tips[center].push_back(nv);
      continue;
    }

    dfs(G, rad, center, d+1, nv, v);
  }
}

int main() {
  int n, k; cin >> n >> k;

  if (k == 1) {
    cout << n-2 << endl;
    return 0;
  }

  Graph G(n);
  vector<P> edge(n-1);
  rep(i,n-1) {
    int a, b; cin >> a >> b; --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
    edge[i] = P(a,b);
  }

  if (k%2 == 0) {
    tips.resize(n);  // from vertex
    vertex.assign(n, 1);
    rep(i,n) {
      dfs(G, k/2, i, 0, i, -1);
    }
  }

  else {
    tips.resize(n-1);  // from edge
    vertex.assign(n, 2);
    rep(i,n-1) {
      int a, b;
      tie(a,b) = edge[i];
      dfs(G, k/2, i, 0, a, b);
      dfs(G, k/2, i, 0, b, a);
    }
  }

  int ans = n - *max_element(all(vertex));
  cout << ans << endl;
  return 0;
}
