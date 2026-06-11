#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n;
  cin >> n;
  map<ll, ll> m;
  rep(i, 0, n) {
    ll x;
    cin >> x;
    m[x]++;
  }
  
  ll m1 = 0, m2 = 0;
  for(const auto& e : m) {
    if(e.second >= 4) {
      m2 = e.first;
      m1 = e.first;
    }
    else if(e.second >= 2) {
      m2 = m1;
      m1 = e.first;
    }
  }
  cout << m1*m2 << "\n";
}