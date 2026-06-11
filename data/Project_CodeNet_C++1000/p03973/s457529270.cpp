#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int p = 1, ans = 0;
  for (int i = 0; i < N; i++) {
    if (p == 1) {
      ans += A[i] - 1;
      p++;
    } else if (A[i] < p) {
      continue;
    } else if (A[i] == p) {
      p++;
    } else {
      ans += (A[i] - 1) / p;
    }
  }

  cout << ans << endl;
  return 0;
}
