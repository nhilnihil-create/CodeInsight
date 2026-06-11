// 解き直し.
// http://agc005.contest.atcoder.jp/data/agc/005/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int io[202020], oi[202020];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N){
        scanf("%d", &io[i]);
        oi[io[i]] = i + 1;
    }
    
    // 2. l, r を 計算(※解説参照).
    LL ans = 0;
    set<int> s;
    s.insert(0);
    s.insert(N + 1);
    // ※ 解説上, N, N - 1, N - 2, ... の 順で, l, r を 求めていくと説明されているが, 
    // 上手く行かなかったので, 1, 2, ... の 順で, l, r を 求めていくように実装している.
    repx(i, 1, N + 1){
        // i の 出現位置.
        int at = oi[i];
        
        // 検索.
        set<int>::iterator itl, itr;
        itl = s.lower_bound(at);
        itr = s.lower_bound(at);
        int l = *(--itl);
        int r = *itr;
        // printf("at=%d l=%d r=%d\n", at, l, r);
        
        // 加算.
        ans += (LL)io[at - 1] * (LL)(at - l) * (LL)(r - at);
        
        // 登録.
        s.insert(at);
    }
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}