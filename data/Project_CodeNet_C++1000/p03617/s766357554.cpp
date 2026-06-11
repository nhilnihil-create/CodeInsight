#include <bits/stdc++.h>
using namespace std;

long long q, h, s, d, n;

int main() {
  cin >> q >> h >> s >> d >> n;
  h = min(h, 2 * q);
  s = min(s, 2 * h);
  d = min(d, 2 * s);
  cout << (n / 2) * d + (n & 1) * s << endl;
  return 0;
}
