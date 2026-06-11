// C++(GCC 9.2.1)
// 解き直し.
// https://img.atcoder.jp/agc012/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using T3 = tuple<int, int, int>;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
const int MAX = 101010;
int dp[MAX][11]; // 頂点 v から 距離 d 以内にある頂点たちの色を塗る.

int main(){
    
    // 1. 入力情報.
    int N, M;
    scanf("%d %d", &N, &M);
    vvi G(N);
    rep(i, M){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    int Q;
    vector<T3> q;
    scanf("%d", &Q);
    rep(i, Q){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        q.emplace_back(a, b, c);
    }
    
    // 2. 色を着色する(操作の逆順).
    function<void(int, int, int, int)> f = [&](int pv, int sv, int d, int c) {
        // 距離が負数の場合は, 終了.
        if(d < 0) return;
        
        // 着色済みの場合は, 終了.
        if(dp[sv][d]) return;
        
        // 着色する.
        rep(i, d + 1) if(!dp[sv][i]) dp[sv][i] = c;
        
        // 隣接する頂点を着色.
        for(auto &cv : G[sv]){
            // 親頂点以外を見に行く.
            if(cv != pv) f(sv, cv, d - 1, c);
        }
    };
    repr(i, Q - 1, 0){
        // 操作を取得.
        int v = get<0>(q[i]);
        int d = get<1>(q[i]);
        int c = get<2>(q[i]);
        
        // 頂点の色を塗ってない場合.
        if(!dp[v][d]) f(-1, v, d, c);
    }
    
    // 3. 出力.
    rep(i, N) printf("%d\n", dp[i][0]);
    return 0;
    
}