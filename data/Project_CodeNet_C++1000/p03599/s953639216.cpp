#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int a, b, c, d, e, f, i, j, k, l, s = 0, w = 100;
  cin >> a >> b >> c >> d >> e >> f;
  a *= 100;
  b *= 100;
  for (i = 0; i <= f; i += a)
    for (j = 0; i + j <= f; j += b)
      for (k = 0; i + j + k <= f; k += c)
        for (l = 0; i + j + k + l <= f; l += d)
          if ((k + l) * (100 + e) <= e * (i + j + k + l) &&
              s * (i + j + k + l) <= (k + l) * (w + s))
            w = i + j, s = k + l;
  cout << w + s << " " << s;
}
