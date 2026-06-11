// 解き直し.
// https://img.atcoder.jp/arc077/editorial.pdf
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int a[202020], b[202020];
LL up[202020], down[202020];

int main(){
    
    // 1. 入力情報.
    int N, M;
    scanf("%d %d", &N, &M);
    rep(i, N) scanf("%d", &a[i]);
    
    // 2. お気に入り(x = 0 -> x = M に 読み替え)を使う場合.
    LL cnt = 0;
    repx(i, 1, N){
        if(a[i - 1] > a[i]) cnt += (LL)(a[i] + (M - a[i - 1] > 0));
        else if(a[i] == M)  cnt++;
        else                cnt += (LL)(a[i] - a[i - 1]);
    }
    
    // 3. 増加分.
    repx(i, 1, N) up[a[i]] += (LL)((a[i] + M - a[i - 1]) % M - 1);
    // rep(i, M + 1) printf("i=%d up=%d\n", i, up[i]);
    
    // 4. 減少分.
    // a[i] と a[i + 1] の 間に x があるような iの個数.
    rep(i, N - 1){
        int s = a[i] + 1;
        if(s > M) s -= M;
        if(a[i + 1] - a[i] > 1){
            b[s]++, b[a[i + 1]]--;
        }
        if(a[i + 1] < a[i] && a[i + 1] + M - a[i] > 1){
            if(s > 1) b[s]++, b[M + 1]--;
            b[1]++, b[a[i + 1]]--;
        }
    }
    rep(i, M) down[i + 1] = down[i] + (LL)b[i + 1];
    // rep(i, M + 1) printf("i=%d down=%d\n", i, down[i]);
    
    // 5. 出力.
    LL ans = cnt, bef = cnt, cur = 0;
    repx(x, 1, M){
        // 今回分更新.
        int idx = (x - 1) == 0 ? M : x - 1;
        cur = bef + up[idx] - down[idx];
        // printf("cur=%d bef=%d up=%d down=%d\n", cur, bef, up[idx], down[idx]);
        
        // 最小値更新.
        ans = min(ans, cur);
        
        // 前回分更新.
        bef = cur;
    }
    printf("%lld\n", ans);
    return 0;
    
}