#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  
  vector<int> M(N);
  M[N - 1] = A[N - 1];
  for (int i = N - 2; i >= 0; --i) {
    if (A[i] > M[i + 1]) M[i] = A[i];
    else M[i] = M[i + 1];
  }
  int m = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (M[i + 1] - A[i] > m) m = M[i + 1] - A[i];
  }
  int ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    if (M[i + 1] - A[i] == m) ++ans;
  }
  cout << ans << endl;
  return 0;
}