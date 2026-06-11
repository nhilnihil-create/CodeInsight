/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define repr4(i,s,n) for(ll i = (n);i>=(s);i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
#define MOD 1000000007;
/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/


int main(){
 // 頂点数と辺数
    int N; cin >> N;

    // グラフ入力受取 (ここでは無向グラフを想定)
    vector<vector<pair<ll,ll>>> G(N+1);
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        ll c;
        cin >> a >> b>>c;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }

    // BFS のためのデータ構造
    vector<ll> dist(N+1, -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;
    int Q,K;
    cin>>Q>>K;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[K] = 0;
    que.push(K); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        rep(j,G[v].size()) {
            if (dist[G[v][j].first] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[G[v][j].first] = dist[v] + G[v][j].second;
            que.push(G[v][j].first);
        }
    }
ll ans[Q];
rep(i,Q){
    int x,y;
    cin>>x>>y;
    ans[i]=dist[x]+dist[y];

}
rep(i,Q){
    cout<<ans[i]<<endl;
}

return 0;
}