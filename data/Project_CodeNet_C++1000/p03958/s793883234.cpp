#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  rep(i, t) cin >> a.at(i);
  int maxV = 0;
  rep(i, t) {
    maxV = max(maxV, a.at(i));
  }
  int res = max(maxV - (k - maxV) - 1, 0);
  cout << res << endl;
  return 0;
}
