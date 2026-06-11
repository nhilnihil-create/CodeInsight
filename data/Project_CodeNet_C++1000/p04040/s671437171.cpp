#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)


const int MAX = 1000005;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int H, W, A, B; cin >> H >> W >> A >> B;
    COMinit();
    ll ans = 0;
    // 下にH-A-1回、右にB+i(0<=i<W-B)回移動する
    // その後一つ下のマスに移動し、それから先ほど右に移動した回数iに応じて
    // 下にA-1回、右にW-B-1-i回移動する
    REP(i,W-B){
        ll tmp = COM(H-A-1+B+i,H-A-1);
        tmp *= COM(A-1+W-B-1-i,A-1);
        tmp %= MOD;
        ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;
    return 0;
}