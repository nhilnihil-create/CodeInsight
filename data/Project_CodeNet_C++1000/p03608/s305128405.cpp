#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
struct edge{ll to,cost;};
const int inf = 1<<28;
const ll INF = 1LL<<53;
const int COMBMAX = 500005;
const ll MOD = 1e9+7;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;++i)
#define repf(i,n) for(int i=0;i<=n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define eachdo(v, e) for(const auto& e : v)
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (ll)distance(v.begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (ll)distance(v.begin(), upper_bound((v).begin(), (v).end(), e))
ll mpow(ll a, ll n,ll mod=MOD){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
template<class T1, class T2> ll bcount(T1 v, T2 a){return upper_index(v,a)-lower_index(v,a);} 
template<class T> bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
template<class T> void debug2(T v){rep(i,v.size()){rep(j,v[i].size())cout<<v[i][j]<<" ";cout<<endl;}}
template<class T> void rdv(T &v){rep(i,v.size())cin>>v[i];}
template<class T> void rdvv(T &v){rep(i,v.size()){rep(j,v[i].size())cin>>v[i][j];}}
// multimap
// mmap.emplace(key,value);
// auto ngw = list.equal_range("");
// for(auto e = ngw.first; it != ngw.second ; ++e)

struct Graph{
public:
ll V;
vector<vector<edge>> Glist;
vector<vector<ll>> Gmatrix;
Graph(ll NodeNum){
    V = NodeNum;
    Glist.resize(V);
}
    void add(ll from,ll to,ll cost = 1){
        Glist[from].push_back({to,cost});
    }

    void UpdateGmatrix() {
        Gmatrix.resize(V);
        rep(i,V){
            Gmatrix[i].resize(V,INF);
            eachdo(Glist[i],e){
                Gmatrix[i][e.to] = e.cost;
            }
        }
    }

    vector<vector<ll>> WarshallFloyd(){
        UpdateGmatrix();
        vector<vector<ll>> dist = Gmatrix;
        rep(i,V) dist[i][i] = 0;
        rep(k,V)rep(i,V)rep(j,V) chmin(dist[i][j],dist[i][k]+dist[k][j]);
        // debug2(dist);
        return dist;
    }

    vector<bool> hasNegativeLoop(){
        vector<bool> ret(V,false);
        vector<ll> dist(V,0);
        rep(loop,2*V-1){
            rep(i,V)eachdo(Glist[i],e){
                if(dist[i] + e.cost < dist[e.to]){
                    dist[e.to] = dist[i] + e.cost;
                    if(V-1 <= loop) ret[e.to] = true;        
                }
            }
        }
        return ret;
    }

    vector<ll> BellmanFord(ll start){
        vector<ll> dist(V,INF);
        dist[start] = 0;
        rep(loop,V-1){
            rep(i,V)eachdo(Glist[i],e){
                if(dist[i] + e.cost < dist[e.to]){
                    dist[e.to] = dist[i] + e.cost;        
                }
            }
        }
        return dist;
    }

    vector<ll> Dijkstra(ll start){
        vector<ll> dist(V,INF);
        priority_queue<P,vector<P>,greater<P>> que;
        dist[start] = 0;
        que.push(P(0,start)); 
        while(!que.empty()){
            P p = que.top();que.pop();
            ll v = p.second;
            if(dist[v]<p.first) continue;
            rep(i,Glist[v].size()){
                edge e = Glist[v][i];
                if(dist[v] + e.cost < dist[e.to]){
                    dist[e.to] = dist[v]+e.cost;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        return dist;
    }
};

int main(){
    ll N,M,R; cin >> N >> M >> R;
    vl r(R);
    rep(i,R){
        cin >> r[i];
        r[i]--;
    }
    sort(all(r));
    Graph g(N);
    rep(i,M){
        ll a,b,c; cin >> a >> b >> c;
        g.add(a-1,b-1,c);
        g.add(b-1,a-1,c);
    }
    vvl d = g.WarshallFloyd();
    ll ans = INF;
    while(next_permutation(all(r))){
        ll cnt = 0;
        rep(i,R-1) cnt += d[r[i]][r[i+1]];
        chmin(ans,cnt);
    }
    cout << ans << endl;

    return 0;
}