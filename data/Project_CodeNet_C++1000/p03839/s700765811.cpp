#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
  constexpr int64_t zero{0};
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int64_t> sa(n + 1);
  vector<int64_t> sb(n + 1);
  for (int i = 0; i < n; i++) {
    sa[i + 1] = sa[i] + a[i];
    sb[i + 1] = sb[i] + max(a[i], zero);
  }
  int64_t ans = numeric_limits<int64_t>::lowest();
  for (int i = 0; i <= n - k; i++) {
    int64_t sum = sb[n] - (sb[i + k] - sb[i]) + max(zero, sa[i + k] - sa[i]);
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
