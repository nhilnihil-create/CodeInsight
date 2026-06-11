#include <iostream>

int main() {
  long long a, b;
  char op;
  std::cin >> a >> op >> b;
  if (op == '+') {
    std::cout << a + b << "\n";
  }
  if (op == '-') {
    std::cout << a - b << "\n";
  }
  return 0;
}