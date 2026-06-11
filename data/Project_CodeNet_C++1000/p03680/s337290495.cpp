#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  rep(i, n) std::cin >> a[i];

  int current = 0;
  rep(i, n) {
    current = a[current] - 1;
    if (current == 1) {
      std::cout << i + 1 << std::endl;
      return 0;
    }
  }

  std::cout << -1 << std::endl;
  return 0;
}
