#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  bool flag = true;
  int c = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    flag = true;
    c = 0;
    for (int j = 0;; ++j) {
      if (s[i + j] != t[j]) {
        flag = false;
        break;
      }
      ++c;

      if (i + j == int(s.size()) - 1) {
        break;
      } else if (j == int(t.size()) - 1) {
        flag = false;
        break;
      }
    }
    if (flag)
      break;
  }

  cout << max(int(s.size() + t.size()) - c, n) << endl;
}
