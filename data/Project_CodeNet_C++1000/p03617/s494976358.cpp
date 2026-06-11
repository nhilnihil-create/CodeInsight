#include <bits/stdc++.h>
using namespace std;

int main() {
  long Q, H, S, D;
  cin >> Q >> H >> S >> D;
  long N;
  cin >> N;
  H = min(Q * 2, H);
  S = min(H * 2, S);
  if (S * 2 <= D) cout << N * S << "\n";
  else cout << N / 2 * D + N % 2 * S << "\n";
}