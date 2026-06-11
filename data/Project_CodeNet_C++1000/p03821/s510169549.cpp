#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  long long ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    ans += B[i] - ((A[i] + ans + B[i] - 1) % B[i] + 1);
  }
  cout << ans << endl;
  return 0;
}