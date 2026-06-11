#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

vector<vector<int>> g;
vector<int> d;
vector<int> tr;
vector<int> sz;

void dfs(int cur, int pre, int dst) {
  tr[cur] = pre;
  d[cur] = dst;
  sz[cur] = 1;
  for (auto&& w : g[cur]) {
    if (w != pre) {
      dfs(w, cur, dst + 1);
      sz[cur] += sz[w];
    }
  }
}

void add_edge(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}

int main() {
  int n;
  cin >> n;
  g.resize(n);
  d.resize(n, inf);
  sz.resize(n, 1);
  tr.resize(n, inf);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    add_edge(a, b);
  }
  dfs(0, -1, 0);
  int t = (d[n - 1]-1) / 2;
  int rt = n - 1;
  for (int i = 0; i < t; i++) rt = tr[rt];

  string ans = ((n - sz[rt] > sz[rt]) ? "Fennec" : "Snuke");
  cout << ans << endl;
//  cerr << rt << " " << sz[rt] << endl;
//  for (auto&& w : sz) cerr << sz[w] << " ";
}
