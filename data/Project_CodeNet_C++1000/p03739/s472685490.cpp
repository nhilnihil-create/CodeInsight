#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;

int n;
vector<ll> a;


ll cost(bool sign) {
  ll cst = 0, rs = 0;
  for (int i = 0; i < n; i++) {
    rs += a[i];
    if (rs == 0) {
      ll x = sign ? 1 : -1;
      cst += 1;
      rs += x;
    } else {
      if ((rs > 0) == true && !sign) {
        cst += rs + 1;
        rs = -1;
      } else if ((rs > 0) == false && sign) {
        cst += abs(rs) + 1;
        rs = 1;
      }
    }
    sign = !sign;
  }
  return cst;
}

int main() {
  cin >> n;
  a.resize(n);
  for (ll &i : a) cin >> i;
  ll ans = cost(true);
  ans = min(ans, cost(false));
  cout << ans << endl;
  return 0;
}
