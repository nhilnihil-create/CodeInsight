#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }

  sort(A.begin(), A.end());
  if (A.back() < K) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  int gcd = A[0];
  for (int i = 1; i < N; ++i) {
    gcd = __gcd(gcd, A[i]);
  }
  if (K % gcd == 0)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
