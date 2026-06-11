#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  long long one = min({Q * 4, H * 2, S});
  long long ans;
  if (2 * one <= D) {
    ans = N * one;
  } else {
    ans = D * (N / 2) + one * (N % 2);
  }
  cout << ans << endl;
  return 0;
}