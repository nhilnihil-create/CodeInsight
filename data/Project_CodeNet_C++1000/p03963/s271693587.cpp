#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int N, K;
    scanf("%d %d", &N, &K);
    
    // 2. ボールの塗り方としてあり得るもの.
    // -> 隣り合ったボールは別の色で塗る.
    int ans = K;
    rep(i, N - 1) ans *= (K - 1);
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}