#include <iostream>

int main() {
  int n, k;

  std::cin >> n >> k;
  long long ans = k;
  for (int i = 0; i < n - 1; i++) {
    ans *= (k - 1);
  }

  std::cout << ans << "\n";

  return 0;
}