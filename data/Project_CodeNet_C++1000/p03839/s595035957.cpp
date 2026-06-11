#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  vector<ll> b(n + 1), c(n + 1);
  for(int i = 0; i < n; i++){
    b.at(i + 1) = b.at(i) + a.at(i);
    c.at(i + 1) = c.at(i) + max<ll>(0, a.at(i));
  }
  
  ll ans = 0;
  for(int i = 0; i + k <= n; i++){
    ll keep = 0;
    if(b.at(i + k) - b.at(i) > 0) keep += b.at(i + k) - b.at(i);
    keep += c.at(i) + c.at(n) - c.at(i + k);
    
    ans = max(ans, keep);
  }
  
  cout << ans << '\n';
}