#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  long long ans = 1;
  int before = 0;
  for (int i = 0; i < n; ++i) {
    if (s1[i] == s2[i]) {
      if (before == 0)
        ans *= 3;
      else if (before == 2)
        ans *= 1;
      else if (before == 1)
        ans *= 2;
      before = 1;
    } else {
      if (before == 0)
        ans *= 6;
      else if (before == 1)
        ans *= 2;
      else if (before == 2)
        ans *= 3;
      before = 2;
      ++i;
    }
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
