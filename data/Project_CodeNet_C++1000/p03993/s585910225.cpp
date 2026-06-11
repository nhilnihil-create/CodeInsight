#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n+1);
  rep(i, 1, n+1) cin >> a[i];
  rep(i, 1, n+1) {
    if(a[a[i]] == i) ans++;
  }
  cout << ans/2 << "\n";
}