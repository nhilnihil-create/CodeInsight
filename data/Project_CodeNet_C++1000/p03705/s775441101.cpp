#include <bits/stdc++.h>
#include <bits/stdint-intn.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int64_t n, a, b;
  std::cin >> n >> a >> b;

  int64_t dab = b - a;

  if (b - a < 0) {
    std::cout << 0 << std::endl;
  } else if (n == 1) {
    std::cout << (a == b ? 1 : 0) << std::endl;
  } else {
    std::cout << ((n - 1) * b + a) - ((n - 1) * a + b) + 1 << std::endl;
  }
  return 0;
}
