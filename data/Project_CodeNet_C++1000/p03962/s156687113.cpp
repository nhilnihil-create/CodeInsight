#include <bits/stdc++.h>

int main(void)
{
  int a, b, c;
  std::cin >> a >> b >> c;

  int cnt = 3;
  if (a == b) {
    cnt--;

    if (b == c) {
      cnt--;
    }
  }
  else {
    if (b == c) {
      cnt--;
    }
    else if (a == c) {
      cnt--;
    }
  }
  std::cout << cnt << std::endl;
  
  return 0;
}