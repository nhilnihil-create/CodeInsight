#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  // 前処理
  COMinit();
  long long H, W, Hdis, Wdis;
  cin >> H >> W >> Hdis >> Wdis;
  long long Hdiff = H - Hdis;
  long long Wdiff = W - Wdis;
  long long pattern1[Hdiff];
  long long pattern2[Hdiff];
  long long ans = 0;
  for(int i = 0; i < Hdiff; i++){
    pattern1[i] = COM(Wdis + i - 1, i);
  }
  for(int j = 0; j < Hdiff; j++){
    long long Hcanmove = H - j - 1;
    long long Wcanmove = Wdiff - 1;
    pattern2[j] = COM(Hcanmove + Wcanmove, Hcanmove);
  }
  for(int k = 0; k < Hdiff; k++){
    long long patt = (pattern1[k] * pattern2[k]) % MOD;
    ans += patt % MOD;
    ans %= MOD; 
  }
  cout << ans << endl;
  return 0;
}