#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int64_t answer = A[0] / 2;
  A[0] %= 2;
  for(int i = 1; i < N; ++i) {
    if(A[i-1] == 1 && 0 < A[i]) {
      ++answer;
      --A[i];
    }
    answer += int64_t(A[i] / 2);
    A[i] %= 2;
  }
  cout << answer << endl;
  return 0;
}
