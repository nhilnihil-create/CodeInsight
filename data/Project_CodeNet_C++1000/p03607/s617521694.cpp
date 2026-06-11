#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  map<int, bool> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (m.find(a) == m.end()) {
      m.emplace(a, true);
    } else {
      m.erase(a);
    }
  }
  int count = 0;
  for (auto x : m) {
    count++;
  }
  cout << count << endl;
}
