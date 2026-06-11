#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  ll ans = 0;
  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    ans = ans + r - l + 1;
  }

  cout << ans << endl;
  
  return 0;
}