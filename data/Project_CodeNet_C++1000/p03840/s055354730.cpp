#include <iostream>
#include <cstdint>

int main() {
  std::int_fast64_t i, o, t, j, l, s, z;
  std::cin >> i >> o >> t >> j >> l >> s >> z;
  if (
    (i >= 2 && i % 2 == 0 && j % 2 == 1 && l % 2 == 1) ||
    (i % 2 == 1 && j >= 2 && j % 2 == 0 && l % 2 == 1) ||
    (i % 2 == 1 && j % 2 == 1 && l >= 2 && l % 2 == 0) ||
    (i % 2 == 1 && j % 2 == 1 && l % 2 == 1)
  ) {
    std::cout << (i - 1) / 2 * 2 + o + (j - 1) / 2 * 2 + (l - 1) / 2 * 2 + 3 << std::endl;
  } else {
    std::cout << i / 2 * 2 + o + j / 2 * 2 + l / 2 * 2 << std::endl;
  }
  return 0;
}