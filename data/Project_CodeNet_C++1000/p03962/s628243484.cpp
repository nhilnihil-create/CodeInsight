#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // 2. 各ペンキの色の個数をカウント.
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    
    // 3. 出力.
    printf("%d\n", s.size());
    return 0;
    
}