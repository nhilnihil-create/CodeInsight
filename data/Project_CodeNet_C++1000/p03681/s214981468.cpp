#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


const ll mod7 = 1000000000LL + 7;

int main(void) {
  ll n, m;
  cin >> n >> m;
  if (abs(n - m) > 1) {
    cout << 0 << endl;
    return 0;
  }

  if (n == m) {
    ll sum = 1;
    for (int i = 1; i <= n; ++i) {
      sum *= i;
      sum %= mod7;
    }
    sum *= sum;
    sum %= mod7;
    sum *= 2;
    sum %= mod7;
    cout << sum << endl;
    return 0;
  }

  if (n < m) swap(n, m);
  ll sum_n = 1;
  for (int i = 1; i <= n; ++i) {
    sum_n *= i;
    sum_n %= mod7;
  }
  ll sum_m = 1;
  for (int i = 1; i <= m; ++i) {
    sum_m *= i;
    sum_m %= mod7;
  }

  ll ans = sum_n * sum_m % mod7;
  cout << ans << endl;
  
  return 0;
}