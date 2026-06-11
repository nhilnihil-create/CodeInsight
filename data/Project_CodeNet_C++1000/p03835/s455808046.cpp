#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  int k,s;
  cin >> k >> s;
  
  ll cnt=0;
  rep(x,k+1){
    rep(y,k+1){
      if(s-x-y >= 0 && s-x-y <= k){
        cnt++;
      }
    }
  }
  
  cout << cnt << endl;
  
  return(0);
}