#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    char c[20];
    scanf("%s", c);
    int l = strlen(c);
    
    // 2. 判定.
    bool ok = false;
    if(l >= 4 && c[0] == 'Y' && c[1] == 'A' && c[2] == 'K' && c[3] == 'I') ok = true;
    
    // 3. 出力.
    if(ok) printf("%s\n", "Yes");
    else   printf("%s\n", "No");
    return 0;
    
}