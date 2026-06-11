#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(1e10);
  int l;
  cin >> l;
  vector<vector<int>> table(n, vector<int>(20));
  for (int i = 0; i < n; i++) {
    int idx = prev(upper_bound(a.begin(), a.end(), a[i] + l)) - a.begin();
    table[i][0] = idx;
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < n; i++) {
      table[i][j] = table[table[i][j - 1]][j - 1];
    }
  }
  int q;
  cin >> q;
  for (int u = 0; u < q; u++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b) swap(a, b);
    int ans = 0;
    int cur = a;
    for (int j = 19; j >= 0; j--) {
      if (table[cur][j] < b) {
        cur = table[cur][j];
        ans += 1 << j;
      }
    }
    cout << ans + 1 << endl;
  }
  return 0;
}