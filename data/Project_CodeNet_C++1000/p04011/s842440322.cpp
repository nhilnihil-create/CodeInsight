#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  int ans;
  if (n <= k) {
    ans = x * n;
  } else {
    ans = x * k + y * (n - k);
  }

  cout << ans << endl;
  return 0;
}
