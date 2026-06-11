#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int digit(ll x){
  int res = 0;
  while(x > 0){
    x /= 10;
    ++res;
  }
  return res;
}

int main(){
  ll N;
  cin >> N;
  int n = sqrt(N);
  int d = digit(N);
  int ans = d;
  for(int i=1; i<=n; ++i){
    if(N%i == 0){
      d = max(digit(i), digit(N/i));
      ans = min(ans, d);
    }
  }
  cout << ans << endl;
}