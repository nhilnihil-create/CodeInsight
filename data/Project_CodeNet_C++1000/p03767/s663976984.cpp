#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(3 * N);
  rep(i, 3 * N) { cin >> A[i]; }
  sort(A.begin(), A.end());

  int64_t answer = 0;
  for (int i = N; i < 3 * N; i += 2) {
    answer += (int64_t)A[i];
  }
  cout << answer << endl;
  return 0;
}