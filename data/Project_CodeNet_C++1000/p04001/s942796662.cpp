// https://atcoder.jp/contests/arc061/tasks/arc061_a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;

  ll ans = 0;
  int m = S.size() - 1;

  rep(bit, 1 << m) {
    ll cur = S[0] - '0';
    rep(i, m) {
      if (bit & (1 << i)) {
        ans += cur;
        cur = 0;
      }
      cur = cur * 10 + S[i + 1] - '0';
    }
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}
