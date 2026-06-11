#include <iostream>
using ll = long long;

int main() {
  int N;
  std::cin >> N;
  int res{0};
  for (int i = 0; i < N; i++) {
    int l, r;
    std::cin >> l >> r;
    res += r - l + 1;
  }
  std::cout << res << std::endl;
  return 0;
}