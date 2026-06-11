#include "bits/stdc++.h"

using namespace std;

template <typename T>
void printv(const vector<T> &v) {
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    cout << v[i] << " \n"[i == sz - 1];
  }
}

using Graph = vector<vector<int>>;
const int MAX_N = 100010;
Graph g(MAX_N);

int dfs(int cur, int pre) {
  if ((int)g[cur].size() == 1) {
    if (cur == 0) return 1;
    return 0;
  }
  int ch = g[cur].size();
  if (cur != 0) ch--;
  int ok = 0;
  for (auto nxt : g[cur]) {
    if (nxt == pre) continue;
    ok ^= (1+dfs(nxt, cur));
  }
  return ok;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << (dfs(0, -1) ? "Alice" : "Bob") << endl;
}
