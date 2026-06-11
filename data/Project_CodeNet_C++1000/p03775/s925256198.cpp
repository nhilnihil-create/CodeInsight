#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64 n;
  cin >> n;
  int ans;
  for (int64 i = 1; i * i <= n; i++) {
    if (i * (n / i) == n) {
      ans = (int)to_string(n / i).size();
    }
  }
  cout << ans;
  return 0;
}