#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

vector<ll> BellmanFord(vector<vector<pair<ll,ll>>> graph,int s) {
    int n=sz(graph);
    vector<ll> dist(n,LINF);
    dist[s]=0;
    
    rep(i,n-1) {
        rep(from,n) {
            for(auto p:graph[from]) {
                int to=p.first;
                ll cost=p.second;
                chmin(dist[to],(dist[from]==LINF ? LINF : dist[from]+cost));
            }
        }
    }
    
    rep(i,n+1) {
        rep(from,n) {
            for(auto p:graph[from]) {
                int to=p.first;
                ll cost=p.second;
                if(chmin(dist[to],(dist[from]==LINF ? LINF : dist[from]+cost))) {
                    dist[to]=-LINF;
                }
            }
        }
    }
    
    return dist;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> graph(n);
    while(m--) {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--;b--;
        graph[a].emplace_back(b,-c);
    }
    
    auto d=BellmanFord(graph,0);
    if(d[n-1]==-LINF) cout<<"inf"<<endl;
    else cout<<-d[n-1]<<endl;
}
