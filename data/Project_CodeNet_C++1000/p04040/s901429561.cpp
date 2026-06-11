#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define LINT long long
const LINT MOD = 1000000007; //nより大きい素数であってくれ

class COMB{
private:
  LINT n;
  vector<LINT> fac;
  vector<LINT> finv;
  vector<LINT> inv;

public:
  COMB(LINT N)
  : fac(vector<LINT>(N+1, 1)), finv(vector<LINT>(N+1, 1)),
    inv(vector<LINT>(N+1, 1)), n(N)
  {
    COMB::init();
  }

  // テーブルを作る前処理
  void init() {
    for (int i = 2; i < n+1; i++){
        COMB::fac[i] = COMB::fac[i - 1] * i % MOD;
        COMB::inv[i] = MOD - COMB::inv[MOD%i] * (MOD / i) % MOD;
        COMB::finv[i] = COMB::finv[i - 1] * COMB::inv[i] % MOD;
    }
  }

  // 二項係数計算
  //1<= k <= n <=10^7くらいまで
  LINT com(int n, int k){
      if (n < k) return 0;
      if (n < 0 || k < 0) return 0;
      return COMB::fac[n] * (COMB::finv[k] * COMB::finv[n - k] % MOD) % MOD;
  }
};

int main(){
  LINT H, W, A, B;
  cin>>H>>W>>A>>B;

  COMB cm(200000);
  LINT ans=0;
  for(LINT i=0; i<H-A; ++i){
    ans += cm.com(i+B-1, i) * cm.com(H-1-i+W-B-1, H-1-i);
    ans %= MOD;
  }
  cout<<ans<<endl;

  return 0;
}
