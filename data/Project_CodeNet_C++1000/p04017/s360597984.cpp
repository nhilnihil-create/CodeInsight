// 解き直し.
// https://img.atcoder.jp/data/arc/060/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL x[101010];
int r[31][101010]; // i番目 の ホテル から (2 の k乗)以内に到達可能な, 最も右のホテル番号.
int pow2[31];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &x[i]);
    x[N] = 2020202020; // 番兵.
    LL L;
    int Q;
    scanf("%lld %d", &L, &Q);
    
    // 2. 2 の 冪乗 を 保存.
    pow2[0] = 1;
    rep(i, 30) pow2[i + 1] = pow2[i] * 2;
    
    // 3. 二次元配列を更新(解説通り).
    rep(i, N){
        int at = lower_bound(x + i, x + N + 1, x[i] + L) - x;
        if(x[at] > x[i] + L) at--;
        r[0][i] = at;
    }
    rep(k, 31) rep(i, N) r[k + 1][i] = r[k][r[k][i]];
    // rep(k, 31){
    //     rep(i, N) printf("%d ", r[k][i]);
    //     puts("");
    // }
    
    // 4. クエリ回答.
    rep(i, Q){
        // 4-1. 入力情報.
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        if(a > b) swap(a, b);
        
        // 4-2. 探索.
        int ans = 0, idx = a;
        while(idx < b){
            int l = 0, h = 30, m;
            while(l + 1 < h){
                m = (h + l) >> 1;
                if(r[m][idx] >= b) h = m;
                else               l = m;
                // printf("l=%d h=%d m=%d\n", l, h, m);
            }
            ans += pow2[l];
            idx = r[l][idx];
        }
        printf("%d\n", ans);
    }
    return 0;
    
}