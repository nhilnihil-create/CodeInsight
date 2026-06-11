#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

struct UnionFind{
    int num;
    vector<int> par,rank;
    UnionFind(int n):num(n),par(n),rank(n,1){
        iota(all(par),0);
    }
    int root(int x){
        if (par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    bool merge(int x, int y){
        x=root(x),y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){
        return root(x)==root(y);
    }
    int size(int x){
        return rank[root(x)];
    }
    int count(){
        return num;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    UnionFind uf(2*N);
    rep(i,M){
        int u,v; cin >> u >> v; --u,--v;
        uf.merge(u,v+N);
        uf.merge(u+N,v);
    }
    ll a=0,b=0,c=0;
    set<int> s;
    rep(i,N){
        if (uf.size(i)>1){
            ++a;
            int p=uf.root(i),q=uf.root(i+N);
            if (!s.count(p)){
                if (p!=q) ++b;
                else ++c;
                s.insert(p),s.insert(q);
            }
        }
    }
    cout << N*N-a*a+(b+c)*(b+c)+b*b << endl;
}