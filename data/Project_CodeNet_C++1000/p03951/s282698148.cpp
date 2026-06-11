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
  string s, t;
  cin >> n >> s >> t;
  int overlap = 0;
  for (int i = 0; i < s.size(); i++) {
    bool ok = true;
    if (s.size() - i > t.size()) {
      continue;
    }
    for (int j = 0; j < s.size() - i; j++) {
      if (s.at(i + j) != t.at(j)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      overlap = s.size() - i;
      break;
    }
  }
  int res = max({n, (int) s.size() + (int) t.size() - overlap});
  cout << res << endl;
  return 0;
}
