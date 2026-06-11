#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
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
    COMinit();
    ll h,w,a,b;
    cin >> h>>w>>a>>b;
    ll result = 0;
    rep(i,w-b){
        result += fac[h-a-1+b+i]*finv[h-a-1]%MOD*finv[b+i]%MOD*fac[a-1+w-b-1-i]%MOD*finv[a-1]%MOD*finv[w-b-1-i]%MOD;
        result %= MOD;
    }
    cout<<result<<endl;
}
