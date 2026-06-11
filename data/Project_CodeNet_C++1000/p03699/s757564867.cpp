#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> s(n);
  rep(i, n) std::cin >> s[i];

  int ans = 0;
  rep(i, n) { ans += s[i]; }
  sort(s.begin(), s.end());

  if (ans % 10 != 0) {
    std::cout << ans << std::endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] % 10) {
      std::cout << ans - s[i] << std::endl;
      return 0;
    }
  }

  std::cout << 0 << std::endl;
  return 0;
}
