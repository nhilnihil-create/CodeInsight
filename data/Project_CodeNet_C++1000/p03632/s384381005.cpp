#include <algorithm>
#include <iostream>

int main() {
  uint32_t A = 0, B = 0, C = 0, D = 0;
  std::cin >> A >> B >> C >> D;

  uint32_t start = std::max(A, C), end = std::min(B, D);
  std::cout << (end > start ? end - start : 0) << std::endl;
  return 0;
}