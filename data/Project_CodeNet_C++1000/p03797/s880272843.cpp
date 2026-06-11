#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll n, m;
  cin >> n >> m;

  ll ans = 0;
  if (n < m / 2) {
    ans = n;
    m = m - (n * 2);
    ans += m / 4;
  } else {
    ans = m / 2;
  }

  cout << ans << endl;
  
  return 0;
}