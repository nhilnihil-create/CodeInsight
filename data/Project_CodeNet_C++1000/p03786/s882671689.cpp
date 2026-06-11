#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[101010], aCum[101010];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &a[i]);
    
    // 2. sort.
    sort(a, a + N);
    
    // 3. 一次元累積和.
    rep(i, N) aCum[i + 1] = a[i] + aCum[i];
    
    // 4. 最終的に残ることが出来るか？
    int ans = 0;
    rep(i, N){
        // i番目の生き物について調査.
        LL ua = aCum[i + 1];
        int cur = i, bef = i;
        bool ok = true;
        
        while(cur < N && ua < 1010101010){
            // 自身の二倍となる箇所のインデックスを検索.
            cur = upper_bound(a, a + N, ua + ua) - a;
            
            // 前回と等しい場合は, 合体出来ないケースに引っ掛かったと見る.
            // if(cur < N && a[bef + 1] >= aCum[cur]){
            // in13.txt で, WA版 のため, ロジック修正.
            if(cur < N && a[bef] > aCum[cur]){
                ok = false;
                break;
            }
            
            // 合体.
            ua = aCum[cur];
            
            // 前回分更新.
            bef = cur;
        }
        // カウント.
        if(ok) ans++;
    }
    
    // 5. 出力.
    printf("%d\n", ans);
    return 0;
    
}