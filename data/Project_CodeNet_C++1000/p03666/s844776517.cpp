#include <iostream>

int main () {
  long long N, A, B, C, D;
  std::cin >> N >> A >> B >> C >> D;
  bool ans = false;
  for (int up = 0; up < N; ++up) {
    int down = N - 1 - up;
    long long base = A + (up - down) * C;
    long long ma = base + up * (D - C);
    long long mi = base - down * (D - C);
    ans |= mi <= B && B <= ma;
  }
  std::cout << (ans ? "YES" : "NO") << std::endl;
}
