// 解き直し.
// https://img.atcoder.jp/data/agc/004/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[2020], b[2020][2020];

int main(){
    
    // 1. 入力情報.
    int N;
    LL x;
    scanf("%d %lld", &N, &x);
    rep(i, N) scanf("%lld", &a[i]);
    rep(i, N) rep(j, N) b[i][j] = 2020202020202020;
    
    // 2. 事前計算.
    rep(i, N) rep(k, N) b[i][k] = min(b[i][(k - 1 + N) % N], a[(i - k + N) % N]);
    
    // 3. 魔法を唱える回数を固定し全探索.
    LL ans = 2020202020202020;
    rep(k, N){
        LL t = k * x;
        rep(i, N) t += b[i][k];
        ans = min(ans, t);
    }
    
    // 4. 出力.
    printf("%lld\n", ans);
    return 0;
    
}