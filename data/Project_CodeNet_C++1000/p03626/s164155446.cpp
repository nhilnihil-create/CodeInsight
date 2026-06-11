#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;
  long ans, pre, i;
  if (S.at(0) == T.at(0)) ans = 3, pre = 1, i = 1;
  else ans = 6, pre = 2, i = 2;
  for (; i < N; i++) {
    if (S.at(i) == T.at(i)) {
      if (pre == 1) ans *= 2;
      pre = 1;
    } else {
      if (pre == 1) ans *= 2;
      else ans *= 3;
      pre = 2;
      i++;
    }
    ans %= MOD;
  }
  cout << ans << "\n";
}