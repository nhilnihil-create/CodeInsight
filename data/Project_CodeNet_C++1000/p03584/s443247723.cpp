#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  long long int ans = 0;
  for (int i = 0; i < 32; i++) {
    int KK;
    if ((K >> i) & 1) {
      KK = (K ^ (1 << i)) | ((1 << i) - 1);
    } else {
      KK = K;
    }
    long long int tmp = 0;
    for (int j = 0; j < N; j++) {
      if ((KK | A[j]) == KK) {
        tmp += B[j];
      }
    }
    ans = max(tmp, ans);
  }
  cout << ans << endl;
}