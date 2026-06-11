#include <iostream>

int main() {
  int n, k, x, y;
  std::cin >> n >> k >> x >> y;

  if (n < k) {
    std::cout << n * x << "\n";
  } else {
    std::cout << k * x + (n - k) * y << "\n";
  }
}