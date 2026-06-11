#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t x, y;
  cin >> x >> y;
  if (x >= 0 && y >= 0)
  {
    if (y > x)
      cout << y - x << endl;
    else
      cout << (y == 0 ? abs(y - x) + 1 : abs(y - x) + 2) << endl;
  }
  else if (x >= 0 && y < 0)
  {
    cout << abs(abs(y) - abs(x)) + 1 << endl;
  }
  else if (x < 0 && y >= 0)
  {
    cout << min(y - x, abs(abs(y) - abs(x)) + 1) << endl;
  }
  else
  {
    if (y < x)
      cout << abs(y) - abs(x) + 2 << endl;
    else
      cout << abs(abs(x) - abs(y)) << endl;
  }
}
