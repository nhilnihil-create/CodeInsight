#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct edge{ll from, to, cost;};
// v:=頂点数 es:=辺の集合 cost:=始点からの最短経路のコストを格納する配列
// s:=始点(指定しなければ頂点0) g:=終点(指定しなければ頂点v-1)
// 始点から到達可能な負閉路が検出された場合falseを、それ以外の場合trueを返す
bool bell(int v,vector<edge>& es,vector<ll>& cost,ll s=0,ll g=-1){
    if(g==-1)g=v-1;
    cost.assign(v,INF);//負閉路検出は０に初期化
    cost[s] = 0;
    rep(i,v*2){
        for(auto& e : es){
            if(cost[e.from]<INF&&cost[e.from]+e.cost<cost[e.to]){
                if(i>=v-1){
                    //return false;
                    //始点から到達可能で、かつ終点へ到達可能な負閉路が検出された場合falseを、それ以外の場合trueを返す
                    if(e.to==g) return false;
                    else cost[e.to] = -INF;
                }
                else{
                    cost[e.to]=cost[e.from]+e.cost;
                }
            }
        }
    }
    return true;
}
int main(){
    ll n,m;cin >> n >>m;
    vector<edge> v(m);
    rep(i,m){
        cin >> v[i].from >>v[i].to >>v[i].cost;
        v[i].from--;v[i].to--;v[i].cost=-(v[i].cost);
    }
    vl cost;
    if(bell(n,v,cost))cout << -cost[n-1] <<endl;
    else cout << "inf" <<endl;
}