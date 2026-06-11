#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b; cin >> n >> a >> b;
  ll ans;
  ll l = a * (n-1) + b;
  ll r = b * (n-1) + a;
  ans = r - l + 1;
  if (a > b) {
    ans = 0;
  } else {
    if (n == 1) {
      if (a == b) ans = 1;
      else ans = 0;
    }
  }
  cout << ans << endl;
  return 0;
}