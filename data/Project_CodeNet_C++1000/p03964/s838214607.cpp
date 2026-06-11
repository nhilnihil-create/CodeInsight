#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL t[1010], a[1010];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld %lld", &t[i], &a[i]);
    
    // 2. 投票数を計算.
    LL ans = 0, tBef = 0, aBef = 0;
    rep(i, N){
        // 今回分取得.
        LL tCur = t[i];
        LL aCur = a[i];
        
        // 投票数を計算.
        if(!tBef && !aBef){
            ans = t[i] + a[i];
            tBef = t[i];
            aBef = a[i];
            continue;
        }
        
        // 得票数の変化を確認.
        if(tCur < tBef || aCur < aBef){
            LL dt = tBef / tCur;
            LL da = aBef / aCur;
            LL dd = max(dt, da);
            // printf("tBef=%lld tCur=%lld aBef=%lld aCur=%lld\n", tBef, tCur, aBef, aCur);
            if(tCur * dd < tBef || aCur * dd < aBef) dd++;
            tCur *= dd;
            aCur *= dd;
            // printf("tBef=%lld tCur=%lld aBef=%lld aCur=%lld\n", tBef, tCur, aBef, aCur);
        }
        
        // 更新.
        ans = tCur + aCur;
        
        // 前回分更新.
        tBef = tCur;
        aBef = aCur;
    }
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}