#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
  }

  bool ok = false;
  for (auto e: v[1]) {
    for(auto e2: v[e]) {
      if (e2 == n) {
        ok = true;
      }
    }
  }

  if (ok) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  
  return 0;
}