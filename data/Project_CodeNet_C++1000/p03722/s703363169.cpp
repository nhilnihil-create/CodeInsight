#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

struct edge{ll from,to,cost;};
struct graph{
    ll V; //1番でかい頂点番号+1
    vector<edge> es; //辺
    vector<ll> d; //最短距離
 
    graph(ll n){
        init(n);
    }
 
    void init(ll n){ //n:頂点数
        V=n+1; //1-origin
        d.resize(V);
        rep1(i,V-1) d[i]=INF; //1~n
    }
 
    void add_edge(ll from,ll to,ll cost){
        edge e;
        e.from=from;
        e.to=to;
        e.cost=cost;
 
        es.pb(e);
    }
 
    bool bellman_ford(ll s){//O(|V||E|)
        bool loop=false;
        rep1(i,V-1) d[i]=INF;
        d[s]=0;
        
        rep1(i,(V-1)*2){
            bool update=false;
            rep(j,sz(es)){
                edge e=es[j];
                if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
                    d[e.to]=d[e.from]+e.cost;
                    if(i>=V-1){
                        d[e.to]=-INF;
                        loop=true;
                    }
 
                    update=true;
                }
            }
            if(!update) break;
        }
 
        if(loop) return true;
        else return false;
    }
};
/*
 bool(BellmanFord)がtrue:負閉路あり
                    false:負閉路なし
 graph.d[目的地]が-INF:目的地に関与する負の閉路あり
 */

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,M; cin>>N>>M;
    graph G(N);
    rep(i,M){
        ll A,B,C; cin>>A>>B>>C;
        G.add_edge(A-1,B-1,-C);
    }
    G.bellman_ford(0);
    
    if(G.d[N-1]==-INF) cout<<"inf";
    else cout<<-G.d[N-1];
}

