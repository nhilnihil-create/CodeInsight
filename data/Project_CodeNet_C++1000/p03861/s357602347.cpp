#include <bits/stdc++.h>

using ll = long long;

int main(void)
{
  ll a, b, x;
  std::cin >> a >> b >> x;

  ll A = (a-1 < 0) ? 0 : (a-1)/x + 1; 
  ll B = b / x + 1;

  std::cout << B-A << std::endl;

  return 0;
}