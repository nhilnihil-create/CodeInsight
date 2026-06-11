#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int now, int bef, ll cost, vector<ll> &path, const vector<vector<pair<int, ll>>> &T) {
  path[now] = cost;
  for (auto node: T[now]) {
    if (node.first == bef) continue;
    dfs(node.first, now, cost + node.second, path, T);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> T(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    T[a].push_back({b, c});
    T[b].push_back({a, c});
  }
  int q, k;
  cin >> q >> k;
  vector<ll> path(n + 1);
  dfs(k, -1, 0LL, path, T);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << path[x] + path[y] << endl;
  }
  return 0;
}