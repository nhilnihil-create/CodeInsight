#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> T(N);
  rep(i, N) { cin >> T[i]; }
  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }

  int Tpeak;
  int prev = 0;
  vector<bool> Lower(N, true);
  rep(i, N) {
    if (prev < T[i]) Tpeak = i;
    if (prev != T[i]) Lower[i] = false;
    prev = T[i];
  }
  int Apeak;
  prev = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (prev < A[i]) Apeak = i;
    if (prev != A[i]) Lower[i] = false;
    prev = A[i];
  }

  if (T[Tpeak] != A[Apeak] || Apeak < Tpeak) {
    cout << 0 << endl;
    return 0;
  }

  int64_t answer = 1;
  int64_t mod = 1e9 + 7;
  rep(i, N) {
    if (!Lower[i]) continue;
    answer *= (int64_t)min(T[i], A[i]);
    answer %= mod;
  }
  cout << endl;
  cout << answer << endl;
  return 0;
}
