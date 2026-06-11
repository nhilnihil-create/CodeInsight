#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int sBCum[101010], tBCum[101010];

int main(){
    
    // 1. 入力情報.
    char S[101010], T[101010];
    int Q;
    scanf("%s %s %d", S, T, &Q);
    
    // 2. 文字列S, T の それぞれについて, 'B' の 累積和 を 計算.
    int sl = strlen(S);
    int tl = strlen(T);
    rep(i, sl) sBCum[i + 1] = sBCum[i] + (S[i] == 'B');
    rep(i, tl) tBCum[i + 1] = tBCum[i] + (T[i] == 'B');
    
    // 3. クエリ回答.
    // 各部分文字列について, 'B' の 個数を, 3で割った余りが同じか否かを見る.
    rep(i, Q){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        // 3-1. S の 部分文字列.
        // S の 部分列について, 'B' の 個数.
        int sB = sBCum[b] - sBCum[a - 1];
        // 'A' を 'BB' に 変換したものも加算.
        sB += 2 * (b - a + 1 - sB);
        // 3で割った余り.
        sB %= 3;
        
        // 3-2. T の 部分文字列.
        // T の 部分列について, 'B' の 個数.
        int tB = tBCum[d] - tBCum[c - 1];
        // 'A' を 'BB' に 変換したものも加算.
        tB += 2 * (d - c + 1 - tB);
        // 3で割った余り.
        tB %= 3;
        
        // 3-3. 判定.
        bool ok = (sB == tB);
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
    
}