#include <bits/stdc++.h>

int main(void)
{
  int n, k;
  std::cin >> n >> k;

  uint32_t ans = k;
  n--;
  k--;
  for (int i = 0; i < n; i++) {
    ans *= k;
  }

  std::cout << ans << std::endl;

  return 0;
}