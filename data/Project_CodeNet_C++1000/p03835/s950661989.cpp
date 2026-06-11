#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  int K, S;
  cin >> K >> S;
  
  int ans = 0;
  for (int i = 0; i <= K; ++i) {
    for (int j = 0; j <= K; ++j) {
      int k = S - i - j;
      if (k < 0) continue;
      if (S - i - j <= K) ++ans;
    }
  }

  cout << ans << endl;
  
  return 0;
}