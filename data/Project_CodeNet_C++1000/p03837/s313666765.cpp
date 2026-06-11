#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


//入力
ll n,m;

//Warshall-floyd
ll dp[310][310];//dpテーブルには辺がないところにはINF、i==jには０を入れておく
void warshallfloyd(){
    rep(k,n){
        rep(i,n){
            rep(j,n){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}



struct Edge{
    ll from,to,cost;
};


int main(){
    cin >> n >> m;
    vector<Edge> edge(m);
    rep(i,310)rep(j,310)dp[i][j]=INF;
    rep(i,310)dp[i][i]=0;

    //ワーシャルフロイドで全地点間最短距離を求める
    rep(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        edge[i].from=a;
        edge[i].to=b;
        edge[i].cost=c;
        dp[a][b]=c;
        dp[b][a]=c;
    }
    warshallfloyd();
    ll ans = 0;
    rep(i,m){
        ll a = edge[i].from;
        ll b = edge[i].to;
        ll c = edge[i].cost;
        if(dp[a][b]<c)ans++;
    }
    cout << ans << endl;
    return 0;
}
