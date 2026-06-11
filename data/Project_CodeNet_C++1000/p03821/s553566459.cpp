#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  rep(i, N) { cin >> A[i] >> B[i]; }

  int64_t answer = 0;
  for (int i = N - 1; i >= 0; --i) {
    int64_t current = ((answer + A[i]) % B[i]);
    if (current != 0) {
      answer += (B[i] - current);
    }
  }
  cout << answer << endl;
  return 0;
}