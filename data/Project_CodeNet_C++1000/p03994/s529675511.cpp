// 1_08.txt ～ 1_15.txt で, WA となったため, 修正版 を 再提出.
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int toA[101010];

int main(){
    
    // 1. 入力情報.
    char c[101010];
    int K, total = 0;
    scanf("%s %d", c, &K);
    int l = strlen(c);
    
    // 2. 'a' に 変換できるまでに必要な操作回数は？
    rep(i, l){
        toA[i] = 26 - (c[i] - 'a');
        toA[i] %= 26;
        total += toA[i];
    }
    
    // 3. 操作をちょうどK回行った後の文字列で, 辞書順で最小のものを出力.
    if(K > total){
        int k = (K - total) % 26;
        rep(i, l){
            if(i < l - 1) printf("%c", 'a');
            else          printf("%c\n", 'a' + k);
        }
    }else{
        rep(i, l){
            // ex.
            // 
            // xyz
            // 3
            // -> ayz が 正解の筈だが, xaa と 出力された(1_08.txt 他で, WA となった理由と推測).
            // if(K > toA[i]){
            if(K >= toA[i]){
                c[i] = 'a';
                K -= toA[i];
            }
            if(i == l - 1 && K > 0){
                char t = c[i] + K;
                if(t > 'z') t -= 26;
                c[i] = t;
            }
        }
        rep(i, l) printf("%c", c[i]);
        puts("");
    }
    return 0;
    
}