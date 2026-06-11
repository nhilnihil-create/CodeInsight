#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)

int main() {
  int N, M;
  cin >> N >> M;

  vector<string> A(N);
  for (int i = 0; i != N; ++i) {
    cin >> A[i];
  }
  vector<string> B(M);
  for (int i = 0; i != M; ++i) {
    cin >> B[i];
  }

  for (int i = 0; i <= N - M; ++i) {
    for (int j = 0; j <= N - M; ++j) {
      bool p{true};
      for (int k = 0; p && k != M; ++k) {
        p = equal(begin(B[k]), end(B[k]), begin(A[k+i]) + j);
      }
      if (p) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
