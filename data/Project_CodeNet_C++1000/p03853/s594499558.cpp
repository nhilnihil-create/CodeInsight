#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll h, w;
  cin >> h >> w;

  for (long long i = 0; i < h; i++) {
    vector<char> c(w);
    for (long long j = 0; j < w; j++) {
      cin >> c.at(j);
    }

    for (auto x : c) {
      cout << x;
    }
    cout << endl;
    for (auto x : c) {
      cout << x;
    }
    cout << endl;
  }
}
