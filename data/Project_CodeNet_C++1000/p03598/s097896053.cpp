#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int ans = 0;
  rep(_, N) {
    int x;
    cin >> x;
    ans += 2 * min(x, K - x);
  }
  cout << ans << endl;
  return 0;
}