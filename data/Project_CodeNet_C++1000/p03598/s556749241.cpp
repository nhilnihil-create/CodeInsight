#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> x(n);
  rep(i, n) { std::cin >> x[i]; }

  int ans = 0;
  rep(i, n) { ans += min(x[i] * 2, abs(k - x[i]) * 2); }
  std::cout << ans << std::endl;
  return 0;
}
