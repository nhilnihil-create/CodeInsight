#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr int64_t kZero = 0;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int64_t> s(n + 1);
  vector<int64_t> w(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + (int64_t)a[i];
    w[i + 1] = w[i] + (int64_t)max(a[i], 0);
  }
  int64_t ans = numeric_limits<int64_t>::lowest();
  for (int i = 0; i <= n - k; i++) {
    int64_t sum = w[n] - (w[i + k] - w[i]);
    sum += max(s[i + k] - s[i], kZero);
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}
