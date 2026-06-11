#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
      int a, b; cin >> a >> b;
      g[a-1].push_back(b-1);
      g[b-1].push_back(a-1);
  }
  queue<int> p;
  p.push(0);
  vector<int> dist(n,-1);
  dist[0] = 0;

  while (!p.empty())
  {
    int now = p.front(); p.pop();
    for (auto v: g[now]) {
      if (dist[v] >= 0) continue;
      dist[v] = dist[now] + 1;
      p.push(v);
    }
  }
  if (dist[n-1]==2) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}