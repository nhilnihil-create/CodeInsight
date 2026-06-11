#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i=0;i<(n);++i)
const ll MOD=1e9+7;

template<typename T>
struct NegativeLoop_on_path{
    const T inf=numeric_limits<T>::max();
    struct edge{
        int u,v; T w;
        edge(int u,int v,T w):u(u),v(v),w(w){}
    };
    int n;
    vector<vector<int>> G;
    vector<T> d;
    vector<int> negative;
    NegativeLoop_on_path(int n):n(n),G(n),d(n,inf),negative(n,0){}
    vector<edge> es;
    void add_edge(int u,int v,T c){
        es.emplace_back(u,v,c);
        G[u].emplace_back(v);
    }
    vector<T> build0(){
        for (int i=0;i<n-1;++i){
            for (auto e:es){
                if (d[e.u]==inf) continue;
                if (d[e.u]+e.w<d[e.v]) d[e.v]=d[e.u]+e.w;
            }
        }
        return d;
    }
    void build1(){
        for (int i=0;i<n;++i){
            for (auto e:es){
                if (d[e.u]==inf) continue;
                if (d[e.u]+e.w<d[e.v]){
                    d[e.v]=d[e.u]+e.w;
                    negative[e.v]=1;
                }
                if (negative[e.u]) negative[e.v]=1;
            }
        }
    }
    T shortest_path(int from,int to,int &neg_loop){
        d[from]=0;
        vector<T> res=build0();
        build1();
        neg_loop=negative[to];
        return res[to];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    NegativeLoop_on_path<ll> NL(N);
    rep(i,M){
        int a,b; ll c; cin >> a >> b >> c;
        NL.add_edge(--a,--b,-c);
    }
    int ok=0;
    ll ans=NL.shortest_path(0,N-1,ok);
    if (ok) cout << "inf" << endl;
    else cout << -ans << endl;
}