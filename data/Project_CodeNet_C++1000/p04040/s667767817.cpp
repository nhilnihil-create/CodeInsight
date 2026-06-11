#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int fact[200010];
int H,W,A,B;

void memo_nCr(){
  fact[0] = fact[1] = 1;
  for(int i = 2; i <= H+W-2; i++){
    fact[i] = i * fact[i-1] % MOD;
  }
}

int inverse(int n){ // MODは素数
  int r = 1;
  for(int m = MOD - 2; m > 0; m >>= 1){
    if(m & 1) r = (r * n) % MOD;
    n = (n * n) % MOD;
  }
  return r;
}

int comb(int n,int r){
  return fact[n]*inverse(fact[r])%MOD*inverse(fact[n-r])%MOD;
}

signed main(){

  cin >> H >> W >> A >> B;
  memo_nCr();
  int ans = 0;
  for(int i = B+1; i <= W; i++){
    ans += comb((H-A-1)+(i-1),H-A-1) * comb((A-1)+(W-i),A-1);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
