#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll m) {
  if (!(n % 3)) return 0;
  ll ans = m;
  for (int i = 1; i < n; ++i) {
    ll v[] = {(n - i) * m, i * (m / 2), i * (m - m / 2)};
    sort(v, v + 3);
    ans = min(ans, v[2] - v[0]);
  }
  return ans;
}

int main() {
  ll n, m;
  cin >> n >> m;
  cout << min(solve(n, m), solve(m, n)) << endl;
}
