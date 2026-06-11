#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll k, s;
  cin >> k >> s;

  ll cnt = 0;
  for (long long x = 0; x <= k; x++) {
    for (long long y = 0; y <= k; y++) {
      ll z = s - x - y;
      if (z >= 0 && z <= k) {
        cnt++;
      }
    }
  }

  cout << cnt << endl;
}
