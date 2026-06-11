#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

vector<vector<P>> G;
vector<ll> lists;

void dfs(int p, ll c) {
  for (auto g : G[p]) {
    if (lists[g.first] != -1)
      continue;
    lists[g.first] = c + g.second;
    dfs(g.first, c + g.second);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  lists.resize(n, -1);
  G.resize(n);
  rep(i, 0, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }

  int q, k;
  cin >> q >> k;
  k--;
  lists[k] = 0;
  dfs(k, 0);

  rep(i, 0, q) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << lists[x] + lists[y] << endl;
  }
}
