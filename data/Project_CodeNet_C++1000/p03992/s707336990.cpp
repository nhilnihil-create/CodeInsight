#include <bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    char c[22];
    scanf("%s", c);
    
    // 2. 出力.
    rep(i, 12){
        printf("%c", c[i]);
        if(i == 3) printf(" ");
    }
    puts("");
    return 0;
    
}