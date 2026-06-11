#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K, x, ans = 0;
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (x <= K/2) ans += x * 2;
    else ans += (K - x) * 2;
  }
  
  cout << ans << endl;
}