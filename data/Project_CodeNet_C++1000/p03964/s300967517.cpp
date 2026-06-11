#include <iostream>
#include <cmath>

int main() {
  int n;

  std::cin >> n;

  long long t[1000], a[1000];
  long long ans_t, ans_a;
  for (int i = 0; i < n; i++) {
    std::cin >> t[i] >> a[i];
  }

  ans_t = t[0];
  ans_a = a[0];
  for (int i = 1; i < n; i++) {
    long long x;
    if ((ans_t + t[i] - 1) / t[i] < (ans_a + a[i] - 1) / a[i]) {
      x = (ans_a + a[i] - 1) / a[i];
      ans_t = t[i] * x;
      ans_a = a[i] * x;
    } else {
      x = (ans_t + t[i] - 1) / t[i];
      ans_a = a[i] * x;
      ans_t = t[i] * x;
    }
  }

  std::cout << ans_a + ans_t << "\n";

  return 0;
}