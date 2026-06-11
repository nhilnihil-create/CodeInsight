#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int res = INT_MAX;
  for (char c = 'a'; c <= 'z'; c++) {
    int tmp = 0;
    string ss(s);
    while (true) {
      bool ok = true;
      for (char cc : ss) {
        if (cc != c) {
          ok = false;
          break;
        }
      }
      if (ok) {
        break;
      }
      int n = ss.size();
      string s2(n - 1, c);
      for (int i = 0; i < n - 1; i++) {
        if (ss.at(i) != c && ss.at(i + 1) != c) {
          s2.at(i) = ss.at(i);
        }
      }
      ss = s2;
      tmp++;
    }
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}
