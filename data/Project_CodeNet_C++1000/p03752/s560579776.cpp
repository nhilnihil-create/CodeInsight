#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int64_t answer = numeric_limits<int64_t>::max();
  for (int i = 0; i < (1 << N); i++) {
    if (__builtin_popcount(i) != K) continue;

    int64_t total = 0;
    int64_t prev = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        int64_t target = max(prev + 1, A[j]);
        total += target - A[j];
        prev = target;
      } else {
        prev = max(prev, A[j]);
      }
    }
    answer = min(total, answer);
  }
  cout << answer << endl;

  return 0;
}
