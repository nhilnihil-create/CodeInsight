#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K, S;
  cin >> K >> S;
  int ans = 0;
  int M = min(K, S);
  for (int i = 0; i <= M; i++) {
    int j, t;
    if (S - i <= K) {
      j = S - i;
      t = 0;
    }
    else {
      j = K;
      t = S - i - j;
    }
    if (t <= K) {
      ans += (abs(j - t) + 1);
    }
  }
  cout << ans << endl;
}