#include <bits/stdc++.h>
using namespace std;

int main() {
  long Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  S = min({Q * 4, H * 2, S});
  if (S * 2 <= D) cout << N * S << "\n";
  else cout << N / 2 * D + N % 2 * S << "\n";
}