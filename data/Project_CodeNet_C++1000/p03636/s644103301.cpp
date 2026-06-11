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

  cout << s.substr(0, 1) + to_string(s.size() - 2) + s.substr(s.size() - 1)
       << endl;
}
