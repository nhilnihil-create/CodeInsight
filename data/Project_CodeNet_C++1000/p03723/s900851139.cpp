#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long A, B, C;
  cin >> A >> B >> C;
  if (A % 2 != 0 && B % 2 != 0 && C % 2 != 0) {
    cout << 0 << endl;
  } else if (A == B && B == C) {
    cout << -1 << endl;
  } else {
    long long ans = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
      long long A_, B_, C_;
      A_ = (B + C) / 2;
      B_ = (A + C) / 2;
      C_ = (A + B) / 2;
      A = A_;
      B = B_;
      C = C_;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}