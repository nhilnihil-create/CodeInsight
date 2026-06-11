// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[303030];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, 3 * N) scanf("%lld", &a[i]);
    
    // 2. sort.
    sort(a, a + 3 * N);
    
    // 3. N組のチームの強さの和としてありうる値の最大値.
    LL ans = 0;
    repex(i, N, 3 * N, 2) ans += a[i];
    
    // 4. 出力.
    printf("%lld\n", ans);
    return 0;
    
}