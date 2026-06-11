#include "bits/stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
typedef vector<ll> vll;

ll mod = 1e9+7;
int main() {
  ll n;cin >> n;
  vll a(n), t(n);
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>t[i];
  vll x(n,-1);
  if(a[n-1] != t[0]) {
    puts("0");
    return 0;
  }
  x[0]=a[0],x[n-1]=t[n-1];
  for(int i=1;i<n;i++){
	if(a[i] > a[i-1]){
      if(x[i] >= 0 && x[i] != a[i]) {
        puts("0");
        return 0;
      }
      x[i] = a[i];
    }
  }
  for(int i=n-2;i>=0;i--){
	if(t[i] > t[i+1]){
      if(x[i] >= 0 && x[i] != t[i]) {
        puts("0");
        return 0;
      }
      x[i] = t[i];
    }
  }
  ll ret = 1;
  rep(i,n){
    //cout << x[i];
    if(x[i] == -1){
      ret *= (ll)min(a[i],t[i]);
      ret %= mod;
    }
    else if(x[i] > min(a[i],t[i])) {
      puts("0");
      return 0;
    }
  }
  cout << ret << endl;
  return 0;
}
