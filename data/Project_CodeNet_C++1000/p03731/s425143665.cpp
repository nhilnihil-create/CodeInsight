#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, T;
  cin >> n >> T;
  vector<ll> t(n);  rep(i, 0, n) cin >> t[i];
  
  ll sum = 0;
  rep(i, 0, n-1)
    sum += max(0LL, t[i+1]-t[i]-T);
  
  cout << t[n-1]+T-sum << "\n";
}