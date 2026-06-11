// 未使用変数(cPrice)を削除し, 再提出.
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const int MAX = 101010;
LL A[MAX];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &A[i]);
    
    // 2. 品物の販売個数が最大になるようにする.
    LL ans = 0, resPrice = 0;
    rep(i, N){
        // 先頭の人には, 価格1 の品物を, (A[0] - 1)個 販売.
        if(i == 0){
            ans += A[i] - 1;
            A[0] = 1;
            resPrice = 2;
            continue;
        }
        
        // すでに販売したメンバーの残価格(resPrice)を比較して, 販売価格をチェック.
        // 等しかったら, メンバーの残価格を, インクリメント.
        if(A[i] == resPrice){
            resPrice++;
            continue;
        }
        
        // 2番目以降の人にも販売.
        LL c = A[i] / resPrice;
        if(A[i] ==  c * resPrice){
            // 価格(resPrice + 1) を 1個販売し, 残りを, 価格resPrice で, 販売.
            if(A[i] > resPrice + 1){
                ans++;
                A[i] -= (resPrice + 1);
                ans += A[i] / resPrice;
                A[i] %= resPrice;
                resPrice = max(resPrice, A[i] + 1);
            }
        }else{
            ans += c;
            A[i] %= resPrice;
            resPrice = max(resPrice, A[i] + 1);
        }
    }
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}