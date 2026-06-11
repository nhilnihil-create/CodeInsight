#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int64_t answer = A[0] - 1;
  int offset = 2;
  for (int i = 1; i < N; ++i) {
    // cout << i << ": " << answer << " offset=" << offset << endl;
    if (A[i] <= offset) {
      offset = max(offset, A[i] + 1);
      continue;
    }
    answer += (int64_t)((A[i] - 1) / offset);
  }
  cout << answer << endl;
  return 0;
}
