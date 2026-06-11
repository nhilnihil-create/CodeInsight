#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  vector<vector<int>> a(26);
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a'].push_back(i + 1);
  }

  int l = 0, r = 0;
  for (int i = 0; i < 26; i++) {
    int m = (int)a[i].size();
    if(m <= 1) continue;
    for (int j = 1; j < m; j++) {
      if(a[i][j] - a[i][j - 1] <= 2) {
        l = a[i][j - 1];
        r = a[i][j];
      }
    }
    if(l != 0) break;
  }
  if(l == 0) cout << -1 << " " << -1 << '\n';
  else cout << l << " " << r << '\n';
}