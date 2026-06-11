#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  vector<int> A(N);
  bool ok = true;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  long long ans = 1;
  if (N % 2 == 1) {
    if (A[0] == 0) {
      for (int i = 1; i < N; i++) {
        if (A[i] != i + i % 2) {
          ok = false;
          break;
        }
      }
    } else {
      ok = false;
    }
  } else {
    for (int i = 0; i < N; i++) {
      if (A[i] != i + (i + 1) % 2) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    for (int i = 0; i < N / 2; i++) {
      ans *= 2;
      ans %= 1000000007;
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}