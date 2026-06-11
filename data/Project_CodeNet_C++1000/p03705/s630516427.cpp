#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  ll res;
  if (a > b) {
    res = 0;
  } else if (n == 1 && a != b) {
    res = 0;
  } else {
    res = ((ll) (n - 1) * b + a) - ((ll) (n - 1) * a + b) + 1;
  }
  cout << res << endl;
  return 0;
}
