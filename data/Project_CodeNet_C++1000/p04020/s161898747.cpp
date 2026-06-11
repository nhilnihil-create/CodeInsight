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
  int64_t res = 0;
  for (int i = 0; i < N; i++) {
    res += A[i] / 2;
    A[i] %= 2;
    if (i + 1 < N && A[i] > 0 && A[i + 1] > 0) {
      A[i]--, A[i + 1]--;
      res++;
    }
  }
  cout << res << '\n';
  return 0;
}
