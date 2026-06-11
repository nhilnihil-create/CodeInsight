#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int main() {
  int N,K;
  int A[15];
  cin >> N >> K;
  rep(i, N) {
    cin >> A[i];
  }
  int comb = (1 << K) - 1;
  long long ans = 1e12;
  while(comb < (1 << N)) {
    long long sum = 0;
    int maxA = 0;
    rep(i, N) {
      if(comb & (1 << i)) {
        if(maxA < A[i]) {
          maxA = A[i];
        } else {
          sum += maxA - A[i] + 1;
          maxA++;
        }
      } else {
        maxA = max(maxA, A[i]);
      }
    }
    ans = min(ans, sum);
    int x = comb & (- comb), y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }
  cout << ans << endl;
  return 0;
}
