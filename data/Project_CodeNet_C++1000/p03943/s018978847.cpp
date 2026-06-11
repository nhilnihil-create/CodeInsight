#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a + b == c || b + c == a || a + c == b) {
    std::cout << "Yes" << "\n";
  } else {
    std::cout << "No" << "\n";
  }
  return 0;
}