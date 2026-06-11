#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  uint32_t N = 0, K = 0;
  std::cin >> N >> K;

  std::vector<uint32_t> L(N);
  for (auto &&l_n : L) std::cin >> l_n;

  std::sort(L.begin(), L.end(), std::greater<uint32_t>());

  std::cout << std::accumulate(L.begin(), L.begin() + K, 0) << std::endl;

  return 0;
}