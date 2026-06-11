#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
#define rem(i, m, n) for (int i = m; i > n; --i)
typedef long long ll;
#define mod 1000000007

int main() {
  int X; cin >> X;
  int cur = 0;
  rep(i, 1, X + 1) {
    cur += i;
    if(cur >= X) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
