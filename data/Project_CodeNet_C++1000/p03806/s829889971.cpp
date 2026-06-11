// コメント, ロジックを修正して再提出.
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const int INF = 2020202020;
int dp[404][404]; // タイプA が a[g], タイプB が b[g] の 場合における 最小価格[円] を 保存.

int main() {
    
    // 1. 入力情報取得.
    int N, Ma, Mb;
    scanf("%d %d %d", &N, &Ma, &Mb);
    
    // 2. dp更新.
    rep(i, N){
        int ca, cb, cc;
        scanf("%d %d %d", &ca, &cb, &cc);
        repr(a, 403, 0){
            repr(b, 403, 0){
                int na = a + ca;
                int nb = b + cb;
                if(na > 403 || nb > 403) continue;
                if(na == ca && nb == cb){
                    // 同じ組み合わせが含まれる場合があるので注意(※以下のロジックを追加).
                    // -> subtask_1_09.txt における 5 4 73 と 5 4 7
                    if(dp[na][nb]) dp[na][nb] = min(dp[na][nb], cc);
                    else           dp[na][nb] = cc;
                }
                if(dp[a][b]){
                    if(dp[na][nb]) dp[na][nb] = min(dp[na][nb], dp[a][b] + cc);
                    else           dp[na][nb] = dp[a][b] + cc;
                }
            }
        }
    }
    
    // 3. 物質C を 生成するための最小予算は？
    int ans = INF;
    rep(i, N + 1){
        int a = Ma * i;
        int b = Mb * i;
        if(a > 400 || b > 400) break;
        if(dp[a][b]) ans = min(ans, dp[a][b]);
    }
    
    // 4. 出力.
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
    
}