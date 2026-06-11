#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
vector<int> a[4];
int cum[4][111];

int main(){

    // 1. 入力情報.
    int N;
    LL W;
    scanf("%d %lld", &N, &W);
    
    // 2. 重さで分類.
    int v;
    LL w1, w;
    rep(i, N){
        scanf("%lld %d", &w, &v);
        if(!i) w1 = w;
        a[w - w1].pb(v);
    }
    
    // 3. sort.
    rep(i, 4){
        sort(all(a[i]));
        reverse(all(a[i]));
    }
    
    // 4. 累積和.
    rep(i, 4) rep(j, a[i].size()) cum[i][j + 1] = cum[i][j] + a[i][j];
    
    // 5. バッグに入れた物の価値の総和の最大値は？
    int ans = 0;
    rep(p, a[0].size() + 1){
        rep(q, a[1].size() + 1){
            rep(r, a[2].size() + 1){
                rep(s, a[3].size() + 1){
                    if(w1 * p + (w1 + 1) * q + (w1 + 2) * r + (w1 + 3) * s <= W){
                        ans = max(ans, cum[0][p] + cum[1][q] + cum[2][r] + cum[3][s]);
                    }
                }
            }
        }
    }
    
    // 6. 出力.
    printf("%d\n", ans);
    return 0;

}