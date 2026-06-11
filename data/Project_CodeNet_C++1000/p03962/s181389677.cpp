#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  if (a == b && b == c && c == a) {
    std::cout << 1 << "\n";
  } else if ((a == b && b != c && c != a) || (a != b && b != c && c == a) || (a != b && b == c && c != a)) {
    std::cout << 2 << "\n";
  } else {
    std::cout << 3 << "\n";
  }

  return 0;
}