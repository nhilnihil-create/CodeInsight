#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  int ans = 100;
  for(int i=1; (ll)i*i<=n; ++i){
    if(n%i == 0){
      ll x = n/i;
      int nans = 0;
      while(x>0){
        x /= 10;
        nans++;
      }
      ans = min(ans,nans);
    }
  }
  cout << ans << endl;
}