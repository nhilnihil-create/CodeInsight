#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
  uint32_t N = 0;
  std::cin >> N;

  std::vector<uint32_t> A(3 * N);
  for (auto &&a_n : A) std::cin >> a_n;

  std::sort(A.begin(), A.end(), std::greater<uint32_t>());
  uint64_t sum = 0;
  for (size_t i = 0; i < N; i++) sum += A[i * 2 + 1];

  std::cout << sum << std::endl;

  return 0;
}