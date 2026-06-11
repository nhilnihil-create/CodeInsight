#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, W;
  cin >> n >> W;
  
  vector<ll> a(1, 0), b(1, 0), c(1, 0), d(1, 0);
  ll w, v, w1;
  cin >> w1 >> v;
  a.emplace_back(v);
  for(int i = 1; i < n; i++){
    cin >> w >> v;
    if(w == w1) a.emplace_back(v);
    if(w == w1 + 1) b.emplace_back(v);
    if(w == w1 + 2) c.emplace_back(v);
    if(w == w1 + 3) d.emplace_back(v);
  }
  
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  sort(d.rbegin(), d.rend());
  
  for(int i = 1; i < a.size() - 1; i++) a.at(i) += a.at(i - 1);
  for(int i = 1; i < b.size() - 1; i++) b.at(i) += b.at(i - 1);
  for(int i = 1; i < c.size() - 1; i++) c.at(i) += c.at(i - 1);
  for(int i = 1; i < d.size() - 1; i++) d.at(i) += d.at(i - 1);
  
  ll ans = 0;
  ll aa, bb, cc, dd;
  aa = bb = cc = dd = 1;
  for(int i = 0; i < a.size(); i++){
    if(a.size() == 1 || i == a.size() - 1) aa = 0;
    for(int j = 0; j < b.size(); j++){
      if(b.size() == 1 || j == b.size() - 1) bb = 0;
      for(int k = 0; k < c.size(); k++){
        if(c.size() == 1 || k == c.size() - 1) cc = 0;
        for(int l = 0; l < d.size(); l++){
          if(d.size() == 1 || l == d.size() - 1) dd = 0;
          if(w1 * (i + 1) * aa + (w1 + 1) * (j + 1) * bb + (w1 + 2) * (k + 1) * cc + (w1 + 3) * (l + 1) * dd <= W){
            ans = max(ans, a.at(i) + b.at(j) + c.at(k) + d.at(l));
          }
          dd = 1;
        }
        cc = 1;
      }
      bb = 1;
    }
    aa = 1;
  }
  
  cout << ans << '\n';
}