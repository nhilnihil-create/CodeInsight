#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++) {
    int cnt = i * m;
    for (int j = 0; j <= m; j++) {
      cnt -= i;
      cnt += n - i;
      if (cnt == k) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}