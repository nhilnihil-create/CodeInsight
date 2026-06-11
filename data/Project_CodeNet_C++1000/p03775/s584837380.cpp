#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vl = vector<ll>;

Vl f(ll n) {
  Vl v;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.emplace_back(i);
      if (i * i != n) v.emplace_back(n / i);
    }
  }
  sort(v.begin(), v.end());
  return v;
}

#define ts(x) to_string(x).size()
void solve() {
  ll N;
  cin >> N;
  Vl d = f(N);
  int ans = 10;
  for (auto a : d) {
    int b = N / a;
    ans = min(ans, (int)max(ts(a), ts(b)));
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}