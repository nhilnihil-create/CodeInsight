#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  ll a[n], b[n], c[m], d[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }

  int ans[n];
  for (int i = 0; i < n; i++) {
    ll dist_min = 1e18;
    for (int j = 0; j < m; j++) {
      ll dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (dist < dist_min) {
        ans[i] = j + 1;
        dist_min = dist;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}