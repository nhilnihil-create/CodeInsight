#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, MOD = 1e9+7;
  cin >> N >> M;
  if (abs(N - M) >= 2) return cout << 0 << "\n", 0;
  long ans = 1;
  if (N == M) ans *= 2;
  while (N) ans = ans * N % MOD, N--;
  while (M) ans = ans * M % MOD, M--;
  cout << ans << "\n";
}