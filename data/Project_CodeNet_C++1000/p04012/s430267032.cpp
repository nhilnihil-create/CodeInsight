#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int a[26];

int main(){
    
    // 1. 入力情報.
    char c[1010];
    scanf("%s", c);
    int l = strlen(c);
    
    // 2. 出現回数をカウント.
    rep(i, l) a[c[i] - 'a']++;
    
    // 3. 判定.
    bool ans = true;
    rep(i, 26) if(a[i] & 1) ans = false;
    
    // 4. 出力.
    printf("%s\n", ans ? "Yes" : "No");
    return 0;
    
}