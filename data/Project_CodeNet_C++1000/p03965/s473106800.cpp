#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int a[101010];

int main(){
    
    // 1. 入力情報.
    char c[101010];
    scanf("%s", c);
    int l = strlen(c);
    
    // 2. AtCoDeerくんが, すべてグーを出したと仮定.
    rep(i, l) if(c[i] == 'p') a[i] = -1;
    
    // 3. 後半すべてパーを出した.
    repr(i, l - 1, (l + 1) / 2) a[i] = (c[i] == 'p') ? 0 : 1;
    
    // 4. 集計.
    int ans = 0;
    rep(i, l) ans += a[i];
    
    // 5. 出力.
    printf("%d\n", ans);
    return 0;
    
}