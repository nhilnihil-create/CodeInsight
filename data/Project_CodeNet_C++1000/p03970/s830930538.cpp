#include <bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    const string s = "CODEFESTIVAL2016";
    char c[22];
    scanf("%s", c);
    
    // 2. 書き換え回数.
    int ans = 0;
    rep(i, 16) if(s[i] != c[i]) ans++;
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}