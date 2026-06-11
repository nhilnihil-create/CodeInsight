#include <bits/stdc++.h>
using namespace std;
int alphabet[26];

int main(){

    // 1. 入力情報.
    int H, W;
    scanf("%d %d", &H, &W);
    char c[111];
    for(int i = 0; i < H; i++){
        scanf("%s", c);
        for(int j = 0; j < W; j++) alphabet[c[j] - 'a']++;
    }
    
    // 2. 条件を満たす回文が存在するかチェック.
    // ex.
    // 基本的には, a[i][j] が, 'x' だったとすると, 
    // a[H - 1 - i][j], a[i][W - 1 - j], a[H - 1 - i][W - 1 - j] も 'x' となる必要があるはず.
    bool ok = true;
    if(H % 2 == 0){
        // 2-1. (H, W) = (偶数, 偶数).
        if(W % 2 == 0){
            for(int i = 0; i < 26; i++) if(alphabet[i] % 4 != 0) ok = false;
        }
        // 2-2. (H, W) = (偶数, 奇数).
        if(W % 2 != 0){
            int rem0 = 0, rem1 = 0, rem2 = 0, rem3 = 0; // 4 で 割った余りを集計.
            for(int i = 0; i < 26; i++){
                if(alphabet[i] % 4 == 0) rem0++;
                if(alphabet[i] % 4 == 1) rem1++;
                if(alphabet[i] % 4 == 2) rem2++;
                if(alphabet[i] % 4 == 3) rem3++;
            }
            // 中央列は, 上半分, 下半分とで, 回文になっている必要がある点に注意.
            if(rem1 > 0 || rem3 > 0) ok = false;
            // 4 の 倍数が少なすぎる場合は, 回文に出来ない.
            if(2 * rem2 > H) ok = false;
        }
    }
    if(H % 2 != 0){
        // 2-3. (H, W) = (奇数, 偶数).
        if(W % 2 == 0){
            int rem0 = 0, rem1 = 0, rem2 = 0, rem3 = 0; // 4 で 割った余りを集計.
            for(int i = 0; i < 26; i++){
                if(alphabet[i] % 4 == 0) rem0++;
                if(alphabet[i] % 4 == 1) rem1++;
                if(alphabet[i] % 4 == 2) rem2++;
                if(alphabet[i] % 4 == 3) rem3++;
            }
            // 中央行は, 左半分, 右半分とで, 回文になっている必要がある点に注意.
            if(rem1 > 0 || rem3 > 0) ok = false;
            // 4 の 倍数が少なすぎる場合は, 回文に出来ない.
            if(2 * rem2 > W) ok = false;
        }
        // 2-4. (H, W) = (奇数, 奇数).
        if(W % 2 != 0){
            int rem0 = 0, rem1 = 0, rem2 = 0, rem3 = 0; // 4 で 割った余りを集計.
            for(int i = 0; i < 26; i++){
                if(alphabet[i] % 4 == 0) rem0++;
                if(alphabet[i] % 4 == 1) rem1++;
                if(alphabet[i] % 4 == 2) rem2++;
                if(alphabet[i] % 4 == 3) rem3++;
            }
            // 中央行, 中央列が, 回文になるために, rem1, rem3 に 制約あることに注意.
            if(rem1 + rem3 > 1) ok = false;
            // 4 の 倍数が少なすぎる場合は, 回文に出来ない.
            if(2 * rem2 > H + W - 2) ok = false;
        }
    }
    
    // 3. 出力
    if(ok) printf("%s\n", "Yes");
    else   printf("%s\n", "No");
    return 0;
    
}