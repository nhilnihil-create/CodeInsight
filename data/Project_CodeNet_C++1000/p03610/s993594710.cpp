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
  string ret;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) {
      ret.push_back(s.at(i));
    }
  }

  cout << ret << endl;
}
