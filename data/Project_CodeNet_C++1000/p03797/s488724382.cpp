#include <iostream>

int main() {
  long long n, m;
  std::cin >> n >> m;
  long long ans = 0;
  if (n * 2 <= m) {
    ans += n;
    m -= 2 * n;
    n = 0;
  } else {
    n -= m / 2;
    ans += m / 2;
    m = 0;
  }
  if (m > 3) {
    ans += m / 4;
    m /= 4;
  }
  std::cout << ans << "\n";
  return 0;
}