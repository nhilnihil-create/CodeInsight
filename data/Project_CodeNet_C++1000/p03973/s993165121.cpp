#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  ll now = 1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (a.at(i) == now) now++;
    else {
      if (a.at(i) % now == 0) ans += (a.at(i) / now) - 1;
      else ans += a.at(i) / now;
      if (now == 1) now++;
    }
  }
  
  cout << ans << '\n';
}