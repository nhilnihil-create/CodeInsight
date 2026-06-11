#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 1;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x = i;
    int cnt = 0;
    while (x) {
      if (x % 2 != 0) {
        break;
      }
      x /= 2;
      cnt++;
    }
    if (mx < cnt) {
      mx = cnt;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
