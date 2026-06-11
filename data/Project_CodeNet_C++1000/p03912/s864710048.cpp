#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <utility>

const int X = 100000;

int main() {
  int n, m, x;
  int ans = 0;
  int c[X + 1] = {};
  int rc[X] = {};
  int pc[X] = {};
  std::cin >> n >> m;
  for (int ni = 0; ni < n; ++ni) {
    std::cin >> x;
    ++c[x];
    ++rc[x % m];
    if (c[x] % 2 == 0) ++pc[x % m];
  }
  for (int r = 0; r < m; ++r) {
    if (r == (m - r) % m) {
      ans += rc[r] / 2;
    } else if (r < m - r) {
      int p = std::min(rc[r], rc[m - r]);
      ans +=  p
            + std::min((rc[r] - p) / 2, pc[r])
            + std::min((rc[m - r] - p) / 2, pc[m - r]);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}