// 解き直し.
// https://img.atcoder.jp/data/arc/060/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL dp[55][55][3030];
int x[55];

int main(){
    
    // 1. 入力情報.
    int N, A;
    scanf("%d %d", &N, &A);
    rep(i, N) scanf("%d", &x[i]);
    
    // 2. dp更新.
    rep(j, N + 1){
        rep(k, N + 1){
            rep(s, N * A + 1){
                if(!j && !k && !s) dp[j][k][s] = 1;
                if(j){
                    if(s < x[j - 1])       dp[j][k][s] = dp[j - 1][k][s];
                    if(k && s >= x[j - 1]) dp[j][k][s] = dp[j - 1][k][s] + dp[j - 1][k - 1][s - x[j - 1]];
                }
            }
        }
    }
    
    // 3. 集計.
    LL ans = 0;
    repx(k, 1, N + 1) ans += dp[N][k][k * A];
    
    // 4. 出力.
    printf("%lld\n", ans);
    return 0;
    
}