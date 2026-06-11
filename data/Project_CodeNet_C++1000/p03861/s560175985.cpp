// ABC 048 Between A and B ...

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll a, ll b, ll x) {
  ll min = a - 1;
  ll div_zero = 0;
  if (min < 0) {
    min = 0;
    div_zero = 1;
  }
  return b / x - min / x + div_zero;
}

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  cout << solve(a, b, x) << endl;
}
