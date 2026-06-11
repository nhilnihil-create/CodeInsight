#include <bits/stdc++.h>
#define rep2(i, n, m) for (int i = m; i < (int)(n); i++)
#define rep(i, n) rep2(i, n, 0)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using lint = long long;  //
template <typename T>
T sq(T x) {
  return x * x;
}
signed main() {
  int a, b, h;
  cin >> a;
  cin >> b;
  cin >> h;
  int ans = (a + b) * h / 2.;
  cout << ans << endl;
  return 0;
}

