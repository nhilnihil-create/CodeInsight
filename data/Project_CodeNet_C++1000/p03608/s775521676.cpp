#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> t(r);
  for (int i = 0; i < r; i++) {
    cin >> t.at(i);
    t.at(i)--;
  }
  sort(t.begin(), t.end());
  vector<vector<int>> d(n, vector<int>(n, 1e9));
  for (int i = 0; i < n; i++) {
    d.at(i).at(i) = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    d.at(a).at(b) = c;
    d.at(b).at(a) = c;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d.at(i).at(j) = min(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
      }
    }
  }
  int ans = 1e9;
  do {
    int s = 0;
    for (int i = 0; i < r - 1; i++) {
      s += d.at(t.at(i)).at(t.at(i + 1));
    }
    ans = min(ans, s);
  } while (next_permutation(t.begin(), t.end()));
  cout << ans << endl;
}
