#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll f(ll x){
  return x * (x+1) / 2;
}

int main(){
  int n; cin >> n;

  ll l = 0, r = n;
  while(r - l > 1){
    ll m = (l + r) / 2;
    if(f(m) >= n){
      r = m;
    }
    else{
      l = m;
    }
  }

  for(int i=1; i<=r; i++){
    if(i == f(r)-n) continue;
    cout << i << endl;
  }

  return 0;
}
