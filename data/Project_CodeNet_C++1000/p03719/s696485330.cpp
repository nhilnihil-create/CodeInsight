#include <bits/stdc++.h>
using namespace std;

int main(){

    // 1. 入力情報.
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // 2. 判定.
    bool ok = (c >= a);
    ok &= (c <= b);
    
    // 3. 出力.
    printf("%s\n", ok ? "Yes" : "No");
    return 0;

}