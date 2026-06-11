#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int64_t res = A.front() - 1;
  int cur = 2;
  for (int i = 1; i < N; i++) {
    if (cur == A[i]) {
      cur++;
    }
    if (cur < A[i]) {
      res += (A[i] - 1) / cur;
    }
  }
  cout << res << '\n';
  return 0;
}
