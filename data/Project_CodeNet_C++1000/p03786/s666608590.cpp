#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());

  vector<int64_t> SUM(N);
  SUM[0] = A[0];
  for (int i = 1; i < N; ++i) {
    SUM[i] = SUM[i - 1] + A[i];
  }

  int64_t answer = 1;
  for (int i = N - 2; i >= 0; --i) {
    if (2 * SUM[i] < A[i + 1]) break;
    ++answer;
  }
  cout << answer << endl;
  return 0;
}
