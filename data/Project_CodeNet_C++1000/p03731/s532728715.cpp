#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){

    // 1. 入力情報.
    int N;
    LL T;
    scanf("%d %lld", &N, &T);
    
    // 2. お湯の出る合計時間は？
    LL ans = 0, s, t, e = 0;
    rep(i, N){
        scanf("%lld", &t);
        s = max(e, t); // 開始時刻.
        e = t + T;     // 終了時刻.
        ans += (e - s);
    }
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;

}