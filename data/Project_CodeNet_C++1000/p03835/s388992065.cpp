#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll k, s;
  cin >> k >> s;

  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k; ++j) {
      ll sum = i + j;
      ll z = s - sum;
      if (z >= 0 && z <= k) {
        ans++;
      }
    }
  }

  cout << ans << '\n';
}