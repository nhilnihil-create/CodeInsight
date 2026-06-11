#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long long a, b, x;
  cin >> a >> b >> x;
  long low, high;
  low = (a + x - 1) / x;
  high = b / x;
  cout << high - low + 1 << endl;
}
