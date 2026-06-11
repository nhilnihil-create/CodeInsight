#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N, M;
  cin >> N >> M;
  int64_t S = 1, I = 1;
  for (int i = 1; i <= N; i++) {
    I *= i;
    I %= 1000000007;
  }
  for (int i = 1; i <= M; i++) {
    S *= i;
    S %= 1000000007;
  }
  if (abs(N - M) > 1) {
    cout << 0 << endl;
  }
  else if ((N - M) == 0) {
    int64_t ans = I * S;
    ans %= 1000000007;
    ans *= 2;
    ans %= 1000000007;
    cout << ans << endl;
  }
  else {
    int64_t ans = I * S;
    ans %= 1000000007;
    cout << ans << endl;
  }
}
  