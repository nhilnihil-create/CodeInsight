// 解き直し.
// https://img.atcoder.jp/agc014/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int u[101010];

int main(){
    
    // 1. 入力情報.
    int N, M;
    scanf("%d %d", &N, &M);
    rep(i, M){
        int x, y;
        scanf("%d %d", &x, &y);
        u[x]++;
        u[y]++;
    }
    
    // 2. クエリ の a[i], b[i] の 出現回数をチェック.
    bool ans = true;
    repx(i, 1, N + 1){
        if(u[i] & 1){
            ans = false;
            break;
        }
    }
    
    // 3. 出力.
    // repx(i, 1, N + 1) printf("%d\n", u[i]);
    printf("%s\n", ans ? "YES" : "NO");
    return 0;
    
}