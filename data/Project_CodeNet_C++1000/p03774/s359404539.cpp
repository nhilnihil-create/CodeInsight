#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int64_t> a(n), b(n), c(m), d(m);
  rep(i, n) std::cin >> a[i] >> b[i];
  rep(i, m) std::cin >> c[i] >> d[i];

  std::vector<int> v(n);

  rep(i, n) {
    int64_t minv = 1000000000;
    rep(j, m) {
      uint64_t tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (minv > tmp) {
        minv = tmp;
        v[i] = j + 1;
      }
    }
  }

  rep(i, n) { std::cout << v[i] << std::endl; }
  return 0;
}
