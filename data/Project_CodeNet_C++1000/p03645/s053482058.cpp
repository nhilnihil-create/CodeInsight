#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }

  vector<set<int>> g(n);
  rep(i, m) {
    g[a[i]].insert(b[i]);
    g[b[i]].insert(a[i]);
  }

  bool possible = false;
  rep(i, n) {
    if (g[i].find(0) != g[i].end() && g[i].find(n-1) != g[i].end()) possible = true;
  }
  if (possible) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}