#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    
    // 1. 入力情報.
    LL A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    
    // 2. 赤いブロックの個数と青いブロックの個数の差を小さくする.
    // 2-1. A, B, C の いずれかが偶数なら, 差は 0 のはず.
    LL ans = 0;
    if((A % 2) * (B % 2) * (C % 2) == 0) ans = 0;
    
    // 2-2. A, B, C が すべて奇数の場合は, A * B, B * C, C * A の 最小値.
    if((A % 2) * (B % 2) * (C % 2) == 1) ans = min({A * B, B * C, C * A});
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}