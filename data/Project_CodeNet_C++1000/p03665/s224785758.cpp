#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int odd = 0;
  rep(i, n) {
    if (a.at(i) % 2 == 1) {
      odd++;
    }
  }
  ll res;
  if (odd == 0) {
    if (p == 0) {
      res = 1LL << n;
    } else {
      res = 0;
    }
  } else {
    res = 1LL << (n - 1);
  }
  cout << res << endl;
  return 0;
}
