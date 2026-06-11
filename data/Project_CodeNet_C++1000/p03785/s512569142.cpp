#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i, n) cin >> t.at(i);
  sort(t.begin(), t.end());
  int res = 0;
  int cur = 0;
  while (cur < n) {
    int next = cur + 1;
    for (int i = 1; i < c && (cur + i < n); i++) {
      if (t.at(cur + i) <= t.at(cur) + k) {
        next++;
        continue;
      }
    }
    res++;
    cur = next;
  }
  cout << res << endl;
  return 0;
}
