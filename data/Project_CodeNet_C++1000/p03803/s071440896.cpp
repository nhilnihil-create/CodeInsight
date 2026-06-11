#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  if (a == 1 || b == 1) {
    if (a == b) {
      std::cout << "Draw" << "\n";
    } else if (a == 1) {
      std::cout << "Alice" << "\n";
    } else if (b == 1) {
      std::cout << "Bob" << "\n";
    }
  } else if (a == b) {
    std::cout << "Draw" << "\n";
  } else if (a < b) {
    std::cout << "Bob" << "\n";
  } else if (a > b) {
    std::cout << "Alice" << "\n";
  }
  return 0;
}