// 解き直し.
// https://img.atcoder.jp/data/agc/004/editorial.pdf
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
int bef[101010];  // テレポーターの情報.
int cur[101010];  // テレポーターの情報(コピー).
int d[101010];    // 首都 からの 距離 を 保存.
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
    int N, K, ans = 0;
    scanf("%d %d", &N, &K);
    vvi G(N);
    rep(i, N){
        scanf("%d", &bef[i]);
        bef[i]--;
        cur[i] = bef[i];
        if(i == 0){
            if(bef[i]) cur[i] = 100000; // 首都から出る辺は首都へ戻る自己ループ.
            continue;
        }
        G[i].pb(bef[i]);
        G[bef[i]].pb(i);
    }
    
    // 2. 首都 から 各頂点までの距離を計算.
    bfs(G, 0, d);
    
    // 3. 首都 から 遠い順に並び替え.
    priority_queue<P> pq;
    repx(i, 1, N) pq.push({d[i], i});
    // while(!pq.empty()){
    //     P p = pq.top();
    //     pq.pop();
    //     printf("dist=%d v=%d\n", p.a, p.b);
    // }
    
    // 4. テレポーターの転送先変更.
    // -> 首都から遠い町から, 首都に向かって, 進み, 
    // (K - 1)進んだら, 終了 を 繰り返す.
    while(!pq.empty()){
        // 頂点を一つ取得.
        P v = pq.top();
        pq.pop();
        
        // 訪問済みか確認, 未訪問なら訪問済みへ.
        if(memo[v.b]) continue;
        memo[v.b] = 1;
        
        // 親頂点へ繰り返し移動.
        int move = 0;
        int c = v.b;    // 子頂点.
        int p = bef[c]; // 親頂点.
        while(p > 0 && !memo[p]){
            if(move == K - 1) break;
            move++;        // 移動距離.
            memo[p] = 1;   // 訪問済みに設定.
            c = p;         // 子頂点.
            p = bef[c];    // 親頂点.
        }
        
        // テレポーターの転送先が, 首都でない場合は, 首都に変更.
        if(p && move == K - 1) cur[c] = 100000;
    }
    // rep(i, N) printf("%d ", bef[i]);
    // puts("");
    // rep(i, N) printf("%d ", cur[i]);
    // puts("");
    
    // 5. テレポーターの転送先変更回数を確認.
    rep(i, N) if(bef[i] != cur[i]) ans++;
    printf("%d\n", ans);
    return 0;
    
}