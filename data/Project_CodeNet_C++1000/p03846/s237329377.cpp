#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M = 1e9+7;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());

  if (N % 2) {
    for (int i = 0; i < N; i++) {
      if (!i) if (A.at(i)) return cout << 0 << "\n", 0;
      int tmp = (i + 2 - 1) / 2 * 2;
      if (A.at(i) != tmp) return cout << 0 << "\n", 0;
    }
  } else {
    for (int i = 0; i < N; i++) {
      int tmp = (i % 2) ? i : i + 1;
      if (A.at(i) != tmp) return cout << 0 << "\n", 0;
    }
  }

  int cnt = N / 2;
  long ans = 1;
  while (cnt--) ans *= 2, ans %= M;
  cout << ans << "\n";
}