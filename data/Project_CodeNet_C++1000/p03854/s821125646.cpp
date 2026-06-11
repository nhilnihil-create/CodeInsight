#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

signed main() {

  string s;
  cin >> s;

  auto it = s.rbegin();

  while (true) {

    bool flag = true;
    if (it + 5 > s.rend()) { flag = false; }

    if (!flag) {
      cout << "NO" << endl;
      return 0;
    }

    switch (*it) {
    case 'm':
      if (*(it + 1) == 'a' && *(it + 2) == 'e' && *(it + 3) == 'r' && *(it + 4) == 'd') {
        it += 5;
      } else {
        flag = false;
      }
      break;
    case 'e':
      if (*(it + 1) == 's' && *(it + 2) == 'a' && *(it + 3) == 'r' && *(it + 4) == 'e') {
        it += 5;
      } else {
        flag = false;
      }
      break;
    case 'r':
      if (*(it + 1) == 'e') {
        if (it + 6 > s.rend()) {
          flag = false;
        } else if (*(it + 2) == 's' && *(it + 3) == 'a' && *(it + 4) == 'r' && *(it + 5) == 'e') {
          it += 6;
        } else if (it + 7 > s.rend()) {
          flag = false;
        } else if (*(it + 2) == 'm' && *(it + 3) == 'a' && *(it + 4) == 'e' && *(it + 5) == 'r' && *(it + 6) == 'd') {
          it += 7;
        } else {
          flag = false;
        }
      } else {
        flag = false;
      }
      break;
    default: flag = false; break;
    }

    if (!flag) {
      cout << "NO" << endl;
      return 0;
    }
    if (it == s.rend()) {
      cout << "YES" << endl;
      return 0;
    }
  }
}
