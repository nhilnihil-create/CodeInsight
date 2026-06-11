#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n), b(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    b.at(a.at(i)) = i;
  }
  
  set<ll> s;
  s.insert(-1);
  s.insert(n);
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    auto it = s.lower_bound(b.at(i));
    it--;
    ans += i * (*s.upper_bound(b.at(i)) - b.at(i)) * (b.at(i) - *it);
    s.insert(b.at(i));
  }
  
  cout << ans << '\n';
}