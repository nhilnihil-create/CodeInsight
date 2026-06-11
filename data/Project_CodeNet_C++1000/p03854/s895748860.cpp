#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  vector<string> e = {"dreamer", "eraser",
                      "dream", "erase"};
  int cur = s.size();
  while (cur > 0) {
    bool ok = false;
    string eee;
    for (string ee : e) {
      bool ok2 = true;
      for (int j = 0; j < ee.size(); j++) {
        if (cur - (int) ee.size() < 0) {
          ok2 = false;
          break;
        }
        if (s.at(cur - (int) ee.size() + j) != ee.at(j)) {
          ok2 = false;
          break;
        }
      }
      if (ok2) {
        eee = ee;
        ok = true;
        break;
      }
    }
    if (ok) {
      cur -= eee.size();
    } else {
      break;
    }
  }
  cout << (cur == 0 ? "YES" : "NO") << endl;
  return 0;
}
