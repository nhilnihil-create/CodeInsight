#include <bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    char c[101010];
    scanf("%s", c);
    int l = strlen(c);
    
    // 2. 計算を行う.
    char mc[101010];
    repr(i, l - 1, 0){
        mc[i] = c[l - 1 - i];
        if(mc[i] == 'b') mc[i] = 'd';
        else if(mc[i] == 'd') mc[i] = 'b';
        else if(mc[i] == 'p') mc[i] = 'q';
        else if(mc[i] == 'q') mc[i] = 'p';
    }
    
    // 3. 判定.
    bool ok = true;
    rep(i, l) if(c[i] != mc[i]) ok = false;
    
    // 4. 出力.
    printf("%s\n", ok ? "Yes" : "No");
    return 0;
    
}