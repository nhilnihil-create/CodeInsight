/**
 *    author:  tourist
 *    created: 20.11.2019 13:56:07       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<long long> k(m + 1);
  vector<long long> b(m + 1);
  auto Add = [&](int from, int to, int kk, int bb) {
    k[from] += kk;
    b[from] += bb;
    k[to + 1] -= kk;
    b[to + 1] -= bb;
  };
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] >= a[i]) {
      int diff = a[i + 1] - a[i];
      Add(0, a[i], 0, diff);
      Add(a[i] + 1, a[i + 1], -1, a[i + 1] + 1);
      Add(a[i + 1] + 1, m - 1, 0, diff);
    } else {
      int diff = a[i + 1] - a[i] + m;
      Add(a[i + 1] + 1, a[i], 0, diff);
      Add(a[i] + 1, m - 1, -1, diff + a[i] + 1);
      Add(0, a[i + 1], -1, a[i + 1] + 1);
    }
  }
  for (int i = 0; i < m; i++) {
    k[i + 1] += k[i];
    b[i + 1] += b[i];
  }
  long long ans = (long long) 9e18;
  for (int i = 0; i < m; i++) {
    ans = min(ans, i * k[i] + b[i]);
  }
  cout << ans << '\n';
  return 0;
}
