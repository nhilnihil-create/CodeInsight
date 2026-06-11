#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int  even = 0;
int main() {
  int n, p;
  cin >> n >> p;
  rep(i,n) {
    int b; cin >> b;
    if (b % 2 == 0) even++;
  }

  ll ans = 1;
  rep(i,n) ans *= 2;
  if (even == n) {
    if (p == 0) cout << ans << endl;
    else cout << 0 << endl;
  }
  else {
    cout << ans / 2 << endl;
  }

  return 0;
}