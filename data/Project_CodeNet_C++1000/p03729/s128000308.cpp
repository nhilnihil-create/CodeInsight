#include <bits/stdc++.h>
using namespace std;

int main(){

    // 1. 入力情報.
    char a[22], b[22], c[22];
    scanf("%s %s %s", a, b, c);
    string A(a), B(b), C(c);
    
    // 2. しりとりになっているか？
    bool ok = (A.back() == B.front());
    ok &= (B.back() == C.front());
    
    // 3. 出力.
    printf("%s\n", ok ? "YES" : "NO");
    return 0;

}