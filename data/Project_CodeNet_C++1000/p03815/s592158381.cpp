#include <iostream>

int main() {
  long long x;

  std::cin >> x;

  if (1 <= x && x <= 6) {
    std::cout << 1 << "\n";
  } else if (7 <= x && x <= 11) {
    std::cout << 2 << "\n";
  } else {
    long long cnt = x / 11 * 2;
    int mod = x % 11;
    if (mod > 6) {
      std::cout << cnt + 2 << "\n";
    } else if (mod != 0) {
      std::cout << cnt + 1 << "\n";
    } else {
      std::cout << cnt << "\n";
    }
  }
  return 0;
}