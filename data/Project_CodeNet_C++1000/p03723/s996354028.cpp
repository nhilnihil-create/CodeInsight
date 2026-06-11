#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    
    // 2. クッキーの交換回数を計算.
    function<int(int, int, int, int)> f = [&](int a, int b, int c, int d) {
        if((a & 1) || (b & 1) || (c & 1)) return d;
        int na = b / 2 + c / 2;
        int nb = c / 2 + a / 2;
        int nc = a / 2 + b / 2;
        if(na == a && nb == b && nc == c) return -1;
        return f(na, nb, nc, ++d);
    };
    int ans = f(A, B, C, 0);
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}