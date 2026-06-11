#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> c(n);
  string res(s);
  int lc = 0;
  int rc = 0;
  int left = n - 1;
  int right = n;
  bool prevIsLeft = false;
  bool prevIsRight = false;
  while (left >= 0) {
    char c = s[left];
    if (c == '(') {
      if (prevIsRight) {
        // 処理なし
      } else {
        // 処理なし
      }
      lc++;
      prevIsLeft = true;
    } else { // ')'
      if (prevIsLeft) {
        while (lc > rc) {
          res.insert(right, ")");
          right++;
          rc++;
        }
      } else {
        // 処理なし
      }
      rc++;
      prevIsRight = true;
    }
    left--;
  }
  if (lc > rc) {
    while (lc > rc) {
      res.insert(right, ")");
      right++;
      rc++;
    }
  } else {
    while (rc > lc) {
      res.insert(0, "(");
      lc++;
    }
  }
  cout << res << endl;
  return 0;
}
