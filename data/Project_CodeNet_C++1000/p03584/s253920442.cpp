#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  ll ans {};
  int mask {};
  K++;
  for (int b = 30; b >= 0; b--) {
    mask ^= (1 << b);
    if (K & (1 << b)) {
      ll sum {};
      for (int i = 0; i < N; i++) {
          if ((A[i] & mask) == 0) sum += B[i];
      }
      ans = max(ans, sum);
      mask ^= (1 << b);
    }
  }
  cout << ans << endl;
  return 0;
}
