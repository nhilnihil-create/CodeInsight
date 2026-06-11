#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll x;
  cin >> x;

  ll ans = 0;
  ans = x / 11 * 2;
  x -= (x / 11) * 11;
  if ( x == 0) ;
  else if (x <= 6) ans++;
  else if (x < 11) ans += 2;

  cout << ans << endl;
  
  return 0;
}