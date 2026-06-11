#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[101010], b[101010];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld %lld", &a[i], &b[i]);
    
    // 2. ボタン押下回数を計算.
    LL ans = 0;
    repr(i, N - 1, 0){
        LL o = a[i] + ans;
        LL q = o / b[i];
        LL r = o % b[i];
        if(r) ans += (q + 1) * b[i] - o;
    }
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}