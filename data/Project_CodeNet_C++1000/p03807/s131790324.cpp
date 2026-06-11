#include <iostream>

int main() {
  uint32_t N = 0, count = 0;
  std::cin >> N;
  for (size_t i = 0; i < N; i++) {
    uint32_t A = 0;
    std::cin >> A;
    count += A % 2;
  }
  std::cout << (count % 2 == 0 ? "YES" : "NO") << std::endl;

  return 0;
}