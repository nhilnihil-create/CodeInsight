#include <iostream>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  int s[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
    sum += s[i];
  }
  std::sort(s, s + n);
  if (sum % 10 == 0) {
    for (int i = 0; i < n; i++) {
      if (s[i] % 10 != 0) {
        sum -= s[i];
        break;
      }
    }
  }
  if (sum % 10 == 0) {
    std::cout << 0 << "\n";
  } else {
    std::cout << sum << "\n";
  }
  return 0;
}