#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n,x;
  cin >> n >> x;
  
  vector<long long> a(n), b(n);
  
  ll ans = 0;
  
  for(ll i=0; i<n; i++){
    cin >> a[i];
    b[i] = a[i];
    ans += a[i];
  }
  
  for(ll j=1; j<n; j++){
    ll now = j*x;
    for(ll i=0; i<n; i++){
      b[i] = min( b[i], a[(i-j+n)%n] );
      now += b[i];
    }
    ans = min( ans, now );
  }
  
  cout << ans << endl;
  
  return 0;
}