#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  if (a * b > c * d) {
    std::cout << a * b << "\n";
  } else {
    std::cout << c * d << "\n";
  }
  return 0;
}