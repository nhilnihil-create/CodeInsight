#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(a.begin(), a.end());
  vector<ll> sum(n);
  rep(i, n) {
    ll aa = (ll) a.at(i);
    if (i == 0) {
      sum.at(i) = aa;
    } else {
      sum.at(i) = sum.at(i - 1) + aa;
    }
  }
  int cur = -1;
  rep(i, n) {
    if (i == n - 1) {
      break;
    }
    if (sum.at(i) * 2 < a.at(i + 1)) {
      cur = i;
    }
  }
  int res = n - (cur + 1);
  cout << res << endl;
  return 0;
}
