#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 200005;

vector<int> g[MAX_N];
int visit[MAX_N];
vector<int> G[MAX_N];
bool vis[MAX_N];

void dfs(int u, int kind){
    visit[u] = kind;
    each(v, g[u]){
        if(visit[v] < 0){
            dfs(v, kind);
        }
    }
}

class UF {
private:
    int sz; vector<int> par,nrank;
public:
    UF(){}
    UF(int node_size){ sz = node_size; par.resize(sz),nrank.resize(sz,0); rep(i,sz) par[i] = i; }
    int find(int x){ if(par[x] == x){ return x; }else{ return par[x] = find(par[x]); } }
    void unite(int x,int y)
    { x = find(x),y = find(y); if(x == y) return;
    	if(nrank[x] < nrank[y]) swap(x,y); par[y] = x; if(nrank[x] == nrank[y]) nrank[x]++; }
    bool same(int x,int y){ return find(x) == find(y); }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, K, L;
    cin >> n >> K >> L;
    rep(i,K){
        int u,v;
        cin >> u >> v;
        g[u-1].pb(v-1), g[v-1].pb(u-1);
    }
    rep(i,n){
        visit[i] = -i-1;
    }
    int kind = 0;
    rep(i,n){
        if(visit[i] < 0){
            dfs(i, kind);
            kind++;
        }
    }
    UF uf(n);
    rep(i,L){
        int u,v;
        cin >> u >> v;
        uf.unite(u-1, v-1);
    }
    map<P, int> mp;
    rep(i,n){
        mp[P(visit[i], uf.find(i))]++;
    }
    rep(i,n){
        cout << mp[P(visit[i], uf.find(i))] << " ";
    }
    cout << "\n";
    return 0;
}