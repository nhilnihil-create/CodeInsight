#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.rbegin(), a.rend());
  vector<long long> ans(n + 1);
  int idx = n;
  for (int i = 0; i < n; i++) {
    idx = min(idx, a[i].second);
    ans[idx] += 1LL * (i + 1) * (a[i].first - a[i + 1].first);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}