#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int N, a, o = 0;
    scanf("%d", &N);
    rep(i, N){
        scanf("%d", &a);
        if(a & 1) o++; // 奇数.
    }
    
    // 2. 黒板に数が 1つだけ残るようにできるか.
    bool ans = o & 1;
    
    // 3. 出力.
    printf("%s\n", ans ? "NO" : "YES");
    return 0;
    
}