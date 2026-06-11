#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[101010];

int main() {
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &a[i]);
    
    // 2. 操作回数を計算.
    // 2-1. + - + - ... の 順.
    LL p = 0, pSum = 0;
    rep(i, N){
        pSum += a[i];
        if(i & 1){
            if(pSum >= 0) p += pSum + 1, pSum = -1;
        }else{
            if(pSum <= 0) p += -pSum + 1, pSum = 1;
        }
    }
    
    // 2-2. - + - + ... の 順.
    LL m = 0, mSum = 0;
    rep(i, N){
        mSum += a[i];
        if(i & 1){
            if(mSum <= 0) m += -mSum + 1, mSum = 1;
        }else{
            if(mSum >= 0) m += mSum + 1, mSum = -1;
        }
    }
    
    // 3. 出力.
    printf("%lld\n", min(p, m));
    return 0;
    
}