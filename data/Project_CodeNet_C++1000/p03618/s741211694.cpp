#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string a;
  cin >> a;
  
  ll ans = a.size() * (a.size() - 1) / 2 + 1;
  
  vector<ll> x(26);
  for(int i = 0; i < a.size(); i++) x.at(a.at(i) - 'a')++;
  
  for(int i = 0; i < 26; i++) ans -= x.at(i) * (x.at(i) - 1) / 2;
  
  cout << ans << '\n';
}