#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
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
int main(){
    long long N,M;
    cin>>N>>M;
    //abs(N-M)>=2なら問答無用で0
    if(abs(N-M)>=2){
        cout << 0 << endl;
        return 0;
    }

    //N!=Mなら犬とサルの場所は確定
    //N>Mなら犬が外、M>Nならサルが外
    //並べ方はN!*M!
    //N=Mならば、犬サル犬サル・・・OR サル犬サル犬・・・の2パターン
    //よってN!*M!*2
    long long ans=1;

    rep2(i,1,N+1){
        ans*=i;
        ans=ans%MOD;
    }
    rep2(i,1,M+1){
        ans*=i;
        ans=ans%MOD;
    }

    if(N==M){
        ans=(ans*2)%MOD;
    }

    cout << ans << endl;



    return 0;
}