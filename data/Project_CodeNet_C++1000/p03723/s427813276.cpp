#include <bits/stdc++.h>
#include <cstdint>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int func(int a, int b, int c) {
  if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
    return 0;
  }

  if (a == b && b == c) {
    return -1;
  }

  return func((a + b) / 2, (a + c) / 2, (b + c) / 2) + 1;
}

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  std::cout << func(a, b, c) << std::endl;
  return 0;
}
