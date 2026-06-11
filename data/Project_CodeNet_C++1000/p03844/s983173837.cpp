#include <bits/stdc++.h>

int main(void)
{
  int a, b;
  char c;
  std::cin >> a >> c >> b;

  int ans;
  if (c == '+') {
    ans = a + b;
  }
  else {
    ans = a - b;
  }

  std::cout << ans << std::endl;

  return 0;
}