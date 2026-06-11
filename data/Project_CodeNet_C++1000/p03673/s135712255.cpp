#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int64_t> a(n);
  rep(i, n) std::cin >> a[i];
  std::vector<int64_t> b;

  rep(i, n) {
    if (n % 2 == 0) {
      if (i % 2 == 0) {
        b.insert(b.end(), a[i]);
      } else {
        b.insert(b.begin(), a[i]);
      }
    } else {
      if (i % 2 != 0) {
        b.insert(b.end(), a[i]);
      } else {
        b.insert(b.begin(), a[i]);
      }
    }
  }

  rep(i, n) {
    if (i != 0) {
      std::cout << " ";
    }
    std::cout << b[i];
  }
  std::cout << std::endl;
  return 0;
}
