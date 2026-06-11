#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
// const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

const int MAX = 1000010;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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

// int main() {
//     // 前処理
//     COMinit();

//     // 計算例
//     cout << COM(100000, 50000) << endl;
// }

int x[60];

map<int,ll> dp[60][2510];


int main () {

    int n,a;cin>>n>>a;

    rep(i,n) cin>>x[i];

    dp[0][0][0]=1;

    ll ans=0;

    rep(i,n) {
        rep(j,2501) {
            for (auto it = dp[i][j].begin();it!=dp[i][j].end();it++) {
                dp[i+1][j][it->first]+=it->second;
                dp[i+1][j+x[i]][it->first+1]+=it->second;
            }
        }
    }

    rep(i,2501) {
        for (auto it = dp[n][i].begin();it!=dp[n][i].end();it++) {
            if ((it->first)==0) continue;
            if (i%(it->first)==0&&i/(it->first)==a) ans+=(it->second);
        }
    }

    cout<<ans<<endl;

}