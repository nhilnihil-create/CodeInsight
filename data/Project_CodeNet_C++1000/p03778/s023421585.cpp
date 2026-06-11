#include <bits/stdc++.h>

int main(void)
{
  int W, a, b;
  std::cin >> W >> a >> b;

  int move;
  if (b >= a && b <= a+W || b+W >= a && b+W <= a+W) {
    move = 0;
  }
  else {
    if (a < b) {
      move = std::abs(b - (a + W));
    }
    else if (a > b) {
      move = std::abs(a - (b + W));
    }
  }

  std::cout << move << std::endl;

  return 0;
}