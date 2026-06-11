#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
  int X; cin >> X;
  int pos = 0;
  int ans = 0;
  rep(i, 1, X + 2) {
    pos += i;
    if (pos >= X) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
