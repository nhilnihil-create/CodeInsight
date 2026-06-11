#include <iostream>
#include <vector>

int main() {
  const unsigned long long mod = 1000000007;
  unsigned N;
  std::cin >> N;
  std::vector<unsigned long long> x(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> x[i];
  }
  unsigned cnt = 0u;
  unsigned cnt2 = 0u;
  unsigned long long ans = 1ull;
  for (unsigned i = 0; i < N; ++i) {
    if (x[i] < 2 * cnt + 1) {
      ans *= (i + 1 - cnt2);
      ans %= mod;
      ++cnt2;
    } else {
      ++cnt;
    }
  }
  for (unsigned i = 0; i < N - cnt2; ++i) {
    ans *= (i + 1);
    ans %= mod;
  }
  std::cout << ans;
  return 0;
}