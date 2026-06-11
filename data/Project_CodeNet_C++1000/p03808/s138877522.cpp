// 解き直し.
// https://img.atcoder.jp/agc010/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[101010], d[101010];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    LL k = 0, one = (LL)(N + 1) * (LL)N / 2;
    rep(i, N){
        scanf("%lld", &a[i]);
        k += a[i];
    }
    
    // 2. 操作回数を計算.
    if(k % one){
        puts("NO");
        return 0;
    }
    k /= one;
    
    // 3. 差分を計算.
    a[N] = a[0];
    rep(i, N) d[i] = a[i + 1] - a[i];
    
    // 4. (d[i] - k) を チェック.
    bool ans = true;
    rep(i, N){
        LL t = d[i] - k;
        if(t > 0 || t % N != 0){
            ans = false;
            break;
        }
    }
    
    // 5. 出力.
    printf("%s\n", ans ? "YES" : "NO");
    return 0;
    
}