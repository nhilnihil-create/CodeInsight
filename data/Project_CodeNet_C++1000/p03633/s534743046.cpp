#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll x, ll y) {
  // assume x > y
  if (x % y == 0)
    return y;
  else
    return gcd(y, x % y);
}

ll lcm(ll x, ll y) {
  // assum x > y
  return x / gcd(x, y) * y;
}

void solve(ll N, vector<ll> T) {
  ll ans(1);
  REP(i, N)
    ans = lcm(max(ans, T[i]), min(ans, T[i]));
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector<ll> T(N);
  REP(i, N)
    cin >> T[i];

  solve(N, move(T));

  return 0;
}
