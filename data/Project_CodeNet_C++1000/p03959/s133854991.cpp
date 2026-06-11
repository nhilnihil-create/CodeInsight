#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  unordered_set<int> determined;
  {
    int prevH = 0;
    for (int i = 0; i < N; i++) {
      if (prevH < A[i]) {
        if (A[i] > B[i]) {
          printf("0\n");
          return 0;
        }
        prevH = A[i];
        determined.insert(i);
      }
    }
  }

  {
    int prevH = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (prevH < B[i]) {
        if (B[i] > A[i]) {
          printf("0\n");
          return 0;
        }
        prevH = B[i];
        determined.insert(i);
      }
    }
  }

  int64_t result = 1;
  for (int i = 0; i < N; i++) {
    if (determined.count(i)) continue;
    result = result * min(A[i], B[i]);
    result %= MOD;
  }
  printf("%ld\n", result);

  return 0;
}
