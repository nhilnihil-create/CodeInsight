#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> P(N);
  rep(i, N) { cin >> P[i]; }

  int64_t step = 1e9 / 3e4;
  vector<int> A(N);
  vector<int> B(N);
  A[0] = 1;
  B[N - 1] = 1;
  rep(i, N - 1) {
    A[i + 1] = A[i] + step;
    B[N - 1 - i - 1] = B[N - 1 - i] + step;
  }
  rep(i, N) { A[P[i] - 1] += i; }

  rep(i, N) {
    if (i != 0) cout << " ";
    cout << A[i];
  }
  cout << endl;

  rep(i, N) {
    if (i != 0) cout << " ";
    cout << B[i];
  }
  cout << endl;
  return 0;
}