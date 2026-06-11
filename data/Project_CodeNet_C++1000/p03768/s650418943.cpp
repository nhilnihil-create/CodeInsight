#include <bits/stdc++.h>
using namespace std;

struct query {
  int v, d, c;
};

long long n, m, q;
vector<vector<int>> g;
vector<query> v;
vector<int> res;
vector<vector<int>> col;

void solve();

int main() {
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  cin >> q;
  v.resize(q);
  for (int i = 0; i < q; ++i) {
    cin >> v[i].v >> v[i].d >> v[i].c;
    --v[i].v;
  }
  solve();
  for (auto p : res) cout << p << endl;
  return 0;
}

void solve() {
  col.assign(n, vector<int>(11, 1000000));
  res.assign(n, 0);
  reverse(v.begin(), v.end());
  for (int i = 0; i < q; ++i)
    if (col[v[i].v][v[i].d] > i) {
      using P = pair<int, int>;
      queue<P> qu;
      qu.push(P(v[i].v, v[i].d));
      col[v[i].v][v[i].d] = i;
      while (qu.size()) {
        P now = qu.front();
        qu.pop();
        if (now.second == 0) continue;
        for (auto to : g[now.first]) {
          P tov = now;
          tov.first = to;
          --tov.second;
          if (col[tov.first][tov.second] > i) {
            col[tov.first][tov.second] = i;
            qu.push(tov);
          }
        }
      }
    }
  for (int i = 0; i < n; ++i) {
    int id = 1000000;
    for (int j = 0; j <= 10; ++j) id = min(id, col[i][j]);
    if (id != 1000000) res[i] = v[id].c;
  }
}
