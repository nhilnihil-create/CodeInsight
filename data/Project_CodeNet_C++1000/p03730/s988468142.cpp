#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  bool ok = false;
  rep(i, b) {
    if ((a * i % b) == c) {
      ok = true;
      break;
    }
  }

  std::cout << (ok ? "YES" : "NO") << std::endl;

  return 0;
}
