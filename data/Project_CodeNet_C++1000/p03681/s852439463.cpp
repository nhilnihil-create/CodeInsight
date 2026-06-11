#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long factmod(int n, long long m){
  long long res = 1;
  while(n > 0){
    res *= n;
    res %= m;
    n--;
  }
  return res;
}

int main(){
  int n, m; cin >> n >> m;
  if(abs(n-m) > 1){
    cout << 0 << endl;
    return 0;
  }
  long long ans;
  if(abs(n-m) == 1){
    ans = factmod(n, mod) * factmod(m, mod) % mod;
  }
  else{
    ans = factmod(n, mod) * factmod(m, mod) % mod * 2 % mod;
  }
  cout << ans << endl;
}