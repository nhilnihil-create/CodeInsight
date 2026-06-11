#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string s;
  cin >> s;
  char now = s.at(0);
  ll ans = 0;
  for (long long i = 1; i < s.size(); i++) {
    if (s.at(i) != now) {
      ans++;
      now = s.at(i);
    }
  }

  cout << ans << endl;
}
