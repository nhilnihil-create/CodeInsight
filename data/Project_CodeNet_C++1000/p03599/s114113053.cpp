#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (double i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  double x, y, ansSum = -1, ansPer = -1, ansY = -1;

  REP(i, 11) {
    REP(j, 11) {
      REP(m, 101) {
        REP(n, 101) {
          x = 100 * (a * i + b * j);
          y = c * m + d * n;

          if (x + y > f) continue;
          if (x / 100 * e < y) continue;

          if (ansPer < 100 * y / (x + y)) {
            ansSum = x + y;
            ansY = y;
            ansPer = 100 * y / (x + y);
          }
        }
      }
    }
  }
  cout << ansSum << " " << ansY << "\n";
}