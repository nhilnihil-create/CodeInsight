#include <bits/stdc++.h>

int main(void)
{
  int n, k, x, y;
  std::cin >> n >> k >> x >> y;

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= k) {
      sum += x;
    }
    else {
      sum += y;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}