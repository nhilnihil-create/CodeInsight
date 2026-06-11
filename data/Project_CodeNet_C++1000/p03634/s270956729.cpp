//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+18;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N;
    cin >> N;
    int a,b;
    ll c;
    vector<vector<pair<int,ll>>> G(N);
    REP(i,N-1){
        cin >> a >> b >>c;
        a--;
        b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    int Q,K;
    cin >> Q >> K;

    vector<int> x(Q),y(Q);
    int tmp1,tmp2;
    REP(i,Q){
        cin >> tmp1>>tmp2;
        x[i]=tmp1-1;
        y[i]=tmp2-1;
    }

    //ダイクストラ O(ElogV)
    // データ構造
    vector<ll> dist(N, INF); // 全頂点を「未訪問」に初期化
    priority_queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[K-1] = 0;
    que.push(K-1); // 0 を橙色頂点にする

    // 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.top(); // 優先度キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (auto itr=G[v].begin();itr!=G[v].end();itr++) {
            // 新たな頂点 nv について距離が短いなら更新
            int nv=itr->first;
            ll cost =itr->second;
            if(dist[v]+cost<dist[nv]){
                dist[nv] = dist[v] + cost;
                que.push(nv);
            }
        }
    }

    
    
    REP(i,Q){
        cout << dist[x[i]]+dist[y[i]] << endl;
    }
    
}