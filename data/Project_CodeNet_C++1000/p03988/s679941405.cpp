// 解き直し.
// http://agc005.contest.atcoder.jp/data/agc/005/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int A[111];

int main(){
    
    // 1. 入力情報.
    int N, a, K = 0;
    scanf("%d", &N);
    rep(i, N){
        scanf("%d", &a);
        A[a]++;
        K = max(K, a); // 直径を取得.
    }
    
    // 2. パスの構築(※解説参照).
    bool f = (K & 1); // 偶奇フラグ.
    bool ok = true;   // 条件を満たす木が構築できるか？
    repr(i, K, K / 2 + 1){
        if(A[i] >= 2) A[i] -= 2;
        else          ok = false;
    }
    // 偶数の場合は, K / 2 も 見る.
    if(!f){
        if(A[K / 2]) A[K / 2]--;
        else         ok = false;
    }
    
    // 3. 最大距離をチェックしながら, 残りの辺を繋げる.
    priority_queue<int> pq;
    rep(i, N) rep(j, A[i]) pq.push(i);
    while(ok && !pq.empty()){
        // 最大距離を取得.
        int k = pq.top();
        pq.pop();
        
        // 偶奇に分けて比較.
        if(f && (k <= (K + 1) / 2)) ok = false;
        if(!f && (k <= K / 2))      ok = false;
    }
    
    // 4. 出力.
    printf("%s\n", ok ? "Possible" : "Impossible");
    return 0;
    
}