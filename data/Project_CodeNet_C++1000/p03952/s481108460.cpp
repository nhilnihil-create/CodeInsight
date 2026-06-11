#include <iostream>

int main() {
  int n, x;
  std::cin >> n >> x;
  int const len = n*2 - 1;

  if (x == 1 || x == len) {
    std::cout << "No" << std::endl;
    return 0;
  }

  std::cout << "Yes" << std::endl;
  for (int i=0; i<len; i++) {
    auto const j = (n + x - 1 + i) % len;
    std::cout << (j+1) << '\n';
  }

  return 0;
}

