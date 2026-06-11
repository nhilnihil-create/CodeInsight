/**
 *    author:  tourist
 *    created: 29.12.2019 20:59:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> b(n);
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; i++) c[i] = make_pair(~a[i], i);
  sort(c.begin(), c.end());
  int mn = n;
  for (int i = 0; i < n; i++) {
    int j = c[i].second;
    mn = min(mn, j);
    b[mn] += (i + 1LL) * (~c[i].first - (i == n - 1 ? 0 : ~c[i + 1].first));
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << '\n';
  }
  return 0;
}
