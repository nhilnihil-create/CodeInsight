#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;

  int calc = abs(y) -abs(x);

  long long res = 1LL << 60;
  if (x <= y) res = min(res, y - x);
  if (-x <= y) res = min(res, y + x + 1);
  if (x <= -y) res = min(res, -y - x + 1);
  if (-x <= -y) res = min(res, -y + x + 2);
  cout << res << endl;
}