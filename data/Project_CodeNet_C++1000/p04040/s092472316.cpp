#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long kai[200010];

void init(){
  kai[0] = 1;
  kai[1] = 1;
  for(int i = 2;i < 200010;i++){
    kai[i] = kai[i-1] * i % MOD;
  }
}

long long pow_mod(long long a, int b){
  long long ans = 1;
  while(b > 0){
    if(b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ans;
}

long long gyaku(long long a){
  return pow_mod(a,MOD-2) % MOD;
}

long long comb(int n, int r){
  return kai[n] * gyaku(kai[n-r]) % MOD * gyaku(kai[r]) % MOD;
}



int main(){
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  init();

  long long ans = 0;

  for(int i = 0;i < h-a;i++){
    ans = (ans + comb(b+i-1, b-1) * comb(w-b-1+h-i-1, w-b-1)) % MOD;
  }

  cout << ans << endl;
  return 0;
}

