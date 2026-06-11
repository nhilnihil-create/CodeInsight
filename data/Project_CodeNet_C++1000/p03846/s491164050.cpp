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
  vector<int> count(n, 0);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    count.at(tmp) += 1;
  }
  int loop_max = (n + 2 - 1) / 2;
  for (int i = 0; i < loop_max; i++) {
    if (n % 2 == 0) {
      if (count.at(2 * i + 1) != 2) {
        cout << 0 << endl;
        return 0;
      }
    } else {
      if (count.at(0) != 1) {
        cout << 0 << endl;
        return 0;
      } else if (i != 0 && count.at(2 * i) != 2 && n != 1) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  long ans = 1;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 0; i < n / 2; i++) {
    ans = (ans * 2);
    ans = ans % (1000000000 + 7);
  }
  cout << ans << endl;
}
