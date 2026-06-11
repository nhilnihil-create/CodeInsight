#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const int MAX = 101010;
LL P[MAX], Q[MAX], PCUM[MAX], QCUM[MAX];

int main(){
    
    // 1. 入力情報.
    int W, H;
    scanf("%d %d", &W, &H);
    rep(i, W) scanf("%lld", &P[i]);
    rep(i, H) scanf("%lld", &Q[i]);
    
    // 2. sort.
    sort(P, P + W);
    sort(Q, Q + H);
    
    // 3. 累積和.
    rep(i, W) PCUM[i + 1] = PCUM[i] + P[i];
    rep(i, H) QCUM[i + 1] = QCUM[i] + Q[i];
    
    // 4. 横方向に見ていき, コストの総和(最小値)を計算.
    // ※縦方向でも同じ結果となるはず.
    LL ans = QCUM[H]; // 0列目を保存.
    // 1列目以降(i列目)は, Q[0], Q[1], ... , Q[H - 1] と (H + 1)個 の P[i - 1] を 併せた集まりから,
    // 小さい方から順に, (H + 1)個 取ってきたものを, 道路として舗装すると見る.
    rep(i, W){
        int at = lower_bound(Q, Q + H, P[i]) - Q;
        LL cost = QCUM[at] + (H + 1 - at) * P[i];
        ans += cost;
    }
    
    // 5. 出力.
    printf("%lld\n", ans);
    return 0;
    
}