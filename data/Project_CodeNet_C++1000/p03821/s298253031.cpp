#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n+1),b(n+1);
  for(ll i=1;i<=n;i++){
    cin >> a[i] >> b[i];
  }
  
  ll ans=0;
  ll times=0;
  for(ll i=n;i>=1;i--){
    ll tmp = (a[i]+times) % b[i];
    //cout << b[i] - tmp << endl;
    if(tmp != 0){
      ans += b[i] - tmp;
      times += (b[i] - tmp);
    }
  }

  cout << ans << endl;
  
  return(0);
}