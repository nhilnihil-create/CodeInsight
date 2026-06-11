#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using Graph = vector<vector<edge>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define query int qq;std::cin >> qq;rep(qqq,qq)
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vout(a) erep(qxqxqx,a)std::cout << qxqxqx << ' ';std::cout  << std::endl;
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
//#define vvector(name,typ,m,n)vector<vector<typ> > name(m,vector<typ> (n))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout <<"Case #" <<qqq+1<<": "
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define ssum(a) accumulate(a,0ll) 

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
//typedef long long T;
ll ceil(ll a,ll b){
    return ((a+b-1)/b);
}
const int INF = 2000000000;
const ll INF64 =3223372036854775807ll;
//const ll INF64 = 9223372036854775807ll;
//const ll INF64 = 9223372036854775ll;
const ll MOD = 1000000007ll;
const dou pi=3.141592653589793;
//mapは、if関数などで覗いただけで構成されるので注意しよう！
//std::vector<vector<int>> g;
//tuple<hoge,huga,foo> tのget関数はget<i>(t)

struct edge {// ダイクストラ法
    ll to, cost;
    edge(ll to,ll cost):
     to(to),cost(cost){}
    
};
typedef vector<vector<edge> > AdjList;  // 隣接リストの型
typedef vector<vector<edge> > Graph;
vector<ll> dist;
typedef pair<int, int> P;
std::vector<ll> dijkstra(AdjList& graph,int n, int s){
    dist = vector<ll>(n,INF64);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0,s));
 
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first){
            continue;
        }
        for(int i=0;i < graph[v].size();i++){
            edge e = graph[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to],e.to));
            }
        }
    }
    return dist;
}
int main(){
    int n;
    std::cin >> n;
    int m;
    std::cin >> m;
    std::vector<int> per;
    
    Graph g(n);
    int rr=0;
    std::cin >> rr;
    std::vector<int> r(rr);
    rep(i,rr){
        std::cin >> r[i];
        r[i]--;
    }
    rep(i,m){
        int a,b,c;
        std::cin >> a>>b>>c;
        a--;b--;
        g[a].pb(edge(b,c));
        g[b].pb(edge(a,c));
    }
    ll ans=INF64;
    map<ll,std::vector<ll>> mp;
    sort(all(r));
    rep(i,rr){
        mp[r[i]] = dijkstra(g,n,r[i]);
    }
    
    do{
        ll dum=0;
        rep(i,rr-1){
            dum+=mp[r[i]][r[i+1]];
        }
        //vout(r);
        //std::cout << dum << std::endl;
        chmin(ans,dum);
    }while(next_permutation(all(r)));
    std::cout << ans << std::endl;
}