// 解き直し.
// https://img.atcoder.jp/agc009/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using P = pair<int, int>;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define a first
#define b second
#define pb push_back
int d[101010];    // 頂点 1 からの 距離 を 保存.
int dp[101010];   // 人 v に対応する頂点を根とした部分木だけに限定した場合のトーナメントの深さの最小値.
int memo[101010]; // 訪問済みフラグ.

// グラフを幅優先探索する.
// https://ja.wikipedia.org/wiki/幅優先探索
// ※bfsの動作確認用.
// @param G: グラフ.
// @param s: グラフの探索開始頂点.
// @param d: 探索開始地点からの距離.
// @return: 特に無し.
void bfs(vvi &G, int s, int* d){
    // 1. 空のキュー.
    queue<int> q;
    
    // 2. 訪問済みフラグ設定.
    d[s] = 0; // スタート地点は, 距離ゼロを指定.
    
    // 3. 探索地点 s をキュー q に追加.
    q.push(s);
    while(!q.empty()){
        // 4. キューから取り出す.
        int u = q.front();
        q.pop();
        
        // 5. 取り出した要素を処理.
        for(auto &e : G[u]){
            // 6. 訪問済であれば, 処理をスキップ.
            if(d[e] > 0)            continue;
            if(d[e] == 0 && e != s) d[e] = d[u] + 1, q.push(e);
        }
    }
    return;
}

int main(){
    
    // 1. 入力情報.
    int N, a;
    scanf("%d", &N);
    vvi G(N);
    rep(i, N - 1){
        scanf("%d", &a);
        a--;
        G[i + 1].pb(a);
        G[a].pb(i + 1);
    }
    
    // 2. 頂点 1 から 各頂点までの距離を計算.
    bfs(G, 0, d);
    
    // 3. 頂点 1 から 遠い順に並び替え.
    priority_queue<P> pq;
    rep(i, N) pq.push({d[i], i});
    // while(!pq.empty()){
    //     P p = pq.top();
    //     pq.pop();
    //     printf("dist=%d v=%d\n", p.a, p.b);
    // }
    
    // 4. dp更新.
    while(!pq.empty()){
        // 頂点を一つ取得.
        P v = pq.top();
        pq.pop();
        
        int p = v.b; // 親頂点.
        
        // 訪問済みならば, Skip.
        if(memo[p]) continue;
        memo[p] = 1;
        
        // 子頂点について, 並び替え.
        priority_queue<P> subPQ;
        for(auto &c : G[p]) subPQ.push({dp[c], c});
        
        // 親頂点 p が, 子頂点 c と 試合を行う.
        int idx = 0;
        while(!subPQ.empty()){
            P c = subPQ.top();
            subPQ.pop();
            if(d[p] < d[c.b]) dp[p] = max(dp[p], dp[c.b] + (++idx));
        }
    }
    // rep(i, N) printf("%d ", dp[i]);
    // puts("");
    
    // 5. 出力.
    printf("%d\n", dp[0]);
    return 0;
    
}