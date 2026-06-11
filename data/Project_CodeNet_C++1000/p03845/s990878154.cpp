#include <bits/stdc++.h>

int main(void)
{
  int n;
  std::cin >> n;

  std::vector<int> t(n), buf(n);
  for (int i = 0; i < n; i++) {
    std::cin >> t[i];
  }

  buf = t;

  int m;
  std::cin >> m;

  for (int i = 0; i < m; i++) {
    int p, x;
    std::cin >> p >> x;
    
    std::swap(t[--p], x);

    int ans = 0;
    for (int j : t) {
      ans += j;
    }
    std::cout << ans << std::endl;

    t = buf;
  }

  return 0;
}