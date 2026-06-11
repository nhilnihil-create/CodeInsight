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
  vector<int> count(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    count.at(tmp) += 1;
  }
  if (n == 1) {
    if (count.at(0) != 1) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << 1 << endl;
      return 0;
    }
  }
  long ans = 1;
  if (n % 2 == 0) {
    for (int i = 1; i < n; i = i + 2) {
      if (count.at(i) != 2) {
        cout << 0 << endl;
        return 0;
      }
      ans *= 2;
      ans %= (1000000000 + 7);
    }
  } else {
    if (count.at(0) != 1) {
      cout << 0 << endl;
      return 0;
    }
    for (int i = 2; i < n; i = i + 2) {
      if (count.at(i) != 2) {
        cout << 0 << endl;
        return 0;
      }
      ans *= 2;
      ans %= (1000000000 + 7);
    }
  }
  cout << ans << endl;
}
