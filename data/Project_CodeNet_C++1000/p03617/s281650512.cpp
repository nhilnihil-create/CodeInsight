#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, q, h, s, d, ans = 0;
  cin >> q >> h >> s >> d >> n;
  ans =
      n / 2 * min({8 * q, 4 * h, 2 * s, d}) + (n % 2) * min({4 * q, 2 * h, s});

  cout << ans << endl;
  return 0;
}
