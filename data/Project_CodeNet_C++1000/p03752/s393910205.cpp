#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// 解説を読んで実装。XORの知識が必要
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];

  ll ans = 100000000000;
  // スイッチの付け方をビット全探索
  for (int bits = 0; bits < (1 << n); bits++) {
    int num_one = __builtin_popcount(bits);
    if (num_one < k) continue;

    ll sum = 0;
    ll max_length = 0;
    vector<ll> B(n, 0);
    rep(i, n) B[i] = A[i];
    for (int i = 0; i < n; i++) {
      if (bits & (1 << i)) {
        if (A[i] <= max_length) {
          sum += max_length - A[i] + 1;
          max_length += 1;
          B[i] = max_length;
        } else {
          max_length = A[i];
        }
      } else {
        max_length = max(max_length, A[i]);
      }
    }
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}
