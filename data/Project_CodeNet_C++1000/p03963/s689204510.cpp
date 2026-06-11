#include <iostream>

uint32_t pow(uint32_t a, uint32_t p) {
  uint32_t ans = 1;
  for (size_t i = 0; i < p; i++) ans *= a;
  return ans;
}

int main() {
  uint32_t N = 0, K = 0;
  std::cin >> N >> K;
  std::cout << K * pow(K - 1, N - 1) << std::endl;
  return 0;
}