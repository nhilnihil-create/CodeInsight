#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n, x, ans;
  cin >> n >> x;
  ans = n;
  function<void(ll, ll)> solve = [&](ll x, ll y) {
    ans += 2LL * (y/x) * x; 
    if( !(y % x)) {
      ans -= x;
    } else {
      solve(y % x, x);
    }
  };
  solve(min(x, n - x), max(x, n - x));
  cout << ans << "\n";
  return 0;
}