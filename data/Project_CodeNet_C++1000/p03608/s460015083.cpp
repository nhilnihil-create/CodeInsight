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
//ダイクストラ O(ElogV)


int main(){
    int N,M,R;
    cin>>N>>M>>R;
    vector<int> r(R);
    vector<vector<ll>> d(N,vector<ll>(N,INF));
    int tmp;
    REP(i,R){
        cin >> tmp;
        tmp--;
        r[i]=tmp;
    }

    // データ構造
    
    vector<vector<ll>> cost(N,vector<ll>(N,-1)); //コスト
    vector<vector<int>> G(N);

    int a,b,c;
    REP(i,M){
        cin>>a>>b>>c;
        a--;
        b--;
        cost[a][b]=c;
        cost[b][a]=c;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    REP(i,R){
        vector<ll> dist(N, INF); // 全頂点を「未訪問」に初期化
        priority_queue<int> que;
        dist[r[i]] = 0;
        que.push(r[i]);
        
        // 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            int v = que.top(); // 優先度キューから先頭頂点を取り出す
            que.pop();

            // v から辿れる頂点をすべて調べる
            for (int nv : G[v]) {
                if (cost[v][nv] == -1) continue; // 行けない行き先ならパス
                // 新たな頂点 nv について距離が短いなら更新
                if(dist[v]+cost[v][nv]<dist[nv]){
                    dist[nv] = dist[v] + cost[v][nv];
                    que.push(nv);
                }
            }
        }
        REP(j,R){
            if(i==j) continue;
            d[r[i]][r[j]]=dist[r[j]];
            d[r[j]][r[i]]=dist[r[j]];
        }
    }

    ll ans=INF;
    ll sum;
    sort(r.begin(),r.end());
    do{
        sum=0;
        REP(i,R-1){
            sum+=d[r[i]][r[i+1]];
        }
        ans=min(ans,sum);
    }while(next_permutation(r.begin(),r.end()));
    cout << ans << endl;
    
    
}