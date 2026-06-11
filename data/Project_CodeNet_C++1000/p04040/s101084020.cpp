#include <iostream>
#include <vector>
 
using namespace std;
 
//combinationを作る前処理
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}
 
const int MAX = 210000;
const int MOD = 1000000007;
 
 
 
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
 
long long com(int n, int k){
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}


int main(){
  
  long long int H , W , A , B;
  
  cin >> H >> W >> A >> B;
  
  COMinit();
  
  long long int ans = 0;
  
  for(int i=0;i<W-B;i++){
    
    ans += (com(A-1+W-B-i-1,A-1)*com(H-A-1+B+i,H-A-1))%1000000007 ;
      ans %= 1000000007;
    
  }
  
  cout << ans << endl;
  
}
    
