#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m; cin >> n >> m;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int c[m], d[m];
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }
  int dis, idx;
  for (int i = 0; i < n; i++) {
    dis = INT_MAX;
    idx = 0;
    for (int j = 0; j < m; j++) {
      if (dis > abs(a[i] - c[j]) + abs(b[i] - d[j])) {
        dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
        idx = j+1;
      }
     }
    cout << idx << '\n';
  }
  return 0;
}