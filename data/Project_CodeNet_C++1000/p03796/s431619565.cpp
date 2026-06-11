#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000000 + 7;


int main(void) {
  ll n;
  cin >> n;

  ll ans = 1;
  for (ll i = 1; i <= n; ++i) {
    ans *= i;
    ans %=  MOD;
  }

  cout << ans << endl;
  
  return 0;
}