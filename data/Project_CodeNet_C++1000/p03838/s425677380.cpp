#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int x, y;
  cin >> x >> y;

  cout
    << abs(abs(y) - abs(x))
      - (y == 0 ? 1 : 0)
      + (signbit(x) == signbit(y)
        ? (x < y ? 0 : 2)
        : 1)
    << endl;
  return 0;
}