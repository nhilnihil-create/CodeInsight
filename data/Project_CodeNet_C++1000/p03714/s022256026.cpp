#include <iostream>
#include <cstdint>
#include <queue>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <limits>

int main() {
  std::int_fast64_t n;
  std::cin >> n;
  std::vector<std::int_fast64_t> a(3 * n);
  std::copy_n(std::istream_iterator<std::int_fast64_t>(std::cin), 3 * n, a.begin());

  std::vector<std::int_fast64_t> left_sum(n + 1);
  left_sum[0] = std::accumulate(a.begin(), a.begin() + n, static_cast<std::int_fast64_t>(0));
  std::priority_queue<std::int_fast64_t, std::vector<std::int_fast64_t>, std::greater<std::int_fast64_t>> left_max_n(a.begin(), a.begin() + n);
  for (std::int_fast64_t i = 1; i <= n; ++i) {
    left_max_n.push(a[n + i - 1]);
    left_sum[i] = left_sum[i - 1] + a[n + i - 1] - left_max_n.top();
    left_max_n.pop();
  }

  std::vector<std::int_fast64_t> right_sum(n + 1);
  right_sum[0] = std::accumulate(a.rbegin(), a.rbegin() + n, static_cast<std::int_fast64_t>(0));
  std::priority_queue<std::int_fast64_t, std::vector<std::int_fast64_t>, std::less<std::int_fast64_t>> right_min_n(a.rbegin(), a.rbegin() + n);
  for (std::int_fast64_t i = 1; i <= n; ++i) {
    right_min_n.push(a[2 * n - i]);
    right_sum[i] = right_sum[i - 1] + a[2 * n - i] - right_min_n.top();
    right_min_n.pop();
  }

  std::int_fast64_t result = std::numeric_limits<std::int_fast64_t>::min();
  for (std::int_fast64_t i = 0; i <= n; ++i) {
    result = std::max(result, left_sum[i] - right_sum[n - i]);
  }
  std::cout << result << std::endl;
  return 0;
}