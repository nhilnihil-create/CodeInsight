#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

const int MAX_N=100010;

int N;
vector<ll> A(MAX_N);
vector<ll> propagate(MAX_N,0);
vector<vector<int>> G(MAX_N);
bool ok=true;

void dfs(int v,int p){
    ll M=0,sum;
    for (auto nv:G[v]){
        if (nv==p) continue;
        dfs(nv,v);
        propagate[v]+=A[nv];
        chmax(M,A[nv]);
    }
    if (M*2<propagate[v]) sum=propagate[v]/2;
    else sum=propagate[v]-M;
    if (p!=-1){
        if (G[v].size()==2&&A[v]!=propagate[v]) ok=false;
        if (G[v].size()>2&&(propagate[v]<A[v]||2*A[v]<propagate[v]||sum<propagate[v]-A[v])) ok=false;
        if (G[v].size()>1) A[v]=2*A[v]-propagate[v];
    }
    else {
        if (G[v].size()==1&&A[v]!=propagate[v]) ok=false;
        if (G[v].size()>1&&2*A[v]!=propagate[v]) ok=false;
    }
}


int main(){
    cin >> N;
    rep(i,N) cin >> A[i];
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1);
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}