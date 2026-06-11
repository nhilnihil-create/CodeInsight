#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string s;
  cin >> s;

  vector<int> count(26, 0);

  for (char c : s) {
    count.at(int(c) - 97)++;
  }
  for (int i = 0; i < 26; i++) {
    if (count.at(i) == 0) {
      cout << char(i + 97) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}
