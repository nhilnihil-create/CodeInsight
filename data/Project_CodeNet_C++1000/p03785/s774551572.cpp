#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,c,k;
  cin >> n >> c >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  ll ans=0;
  ll cnt=0;
  ll i=0;
  ll now=a[0];
  while(i<n){
    ans++;
    i++;
    cnt++;
    while(cnt < c && a[i] <= now+k){
      cnt++;
      i++;
    }
    now = a[i];
    //cout << now << endl;
    cnt = 0;
  }

  cout << ans << endl;
  
  return(0);
}