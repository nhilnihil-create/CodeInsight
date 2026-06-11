#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

template<typename T>
struct edge{
    int src,to;
    T cost;
    edge(int from,int to,T cost):src(src),to(to),cost(cost){}
    edge(int to,T cost):edge(-1,to,cost){}
    operator int()const{return to;}
};

template<typename T>
using Edges=vector<edge<T>>;

template<typename T>
using Graph=vector<Edges<T>>;

void solve(){
    ll x,y;cin>>x>>y;

    vl a={x,y,-x,-y};
    Graph<ll> g(4);
    rep(i,4)rep(j,4){
        if(abs(a[i])==abs(a[j]))g[i].emplace_back(j,1);
        if(a[i]<=a[j])g[i].emplace_back(j,a[j]-a[i]);
    }

    vl d(4,LINF);
    d[0]=0;
    pq<pl> q;
    q.emplace(0,0);
    while(q.size()){
        ll dd,src;
        tie(dd,src)=q.top();q.pop();
        if(dd>d[src])continue;
        for(auto &e:g[src]){
            if(d[e.to]<=d[src]+e.cost)continue;
            d[e.to]=d[src]+e.cost;
            q.emplace(d[e.to],e.to);
        }
    }
    
    cout<<d[1]<<endl;
}