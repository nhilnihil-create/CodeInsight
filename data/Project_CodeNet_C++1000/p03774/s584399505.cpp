#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, i, j, len, minLen, index;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  for (i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (i = 0; i < m; i++) cin >> c[i] >> d[i];
  for (i = 0; i < n; i++) {
    minLen = INT_MAX;
    for (j = 0; j < m; j++) {
      len = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (len < minLen) {
        minLen = len;
        index = j + 1;
      }
    }
    cout << index << endl;
  }
}