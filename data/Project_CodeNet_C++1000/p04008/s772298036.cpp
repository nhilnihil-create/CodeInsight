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

const int MAX_N=100010;

int N,K,ans=0;
vector<vector<int>> G(MAX_N);
vector<int> md(MAX_N,0);
map<int,int> par;

void dfs(int v){
    md[v]=1;
    for (auto nv:G[v]){
        dfs(nv);
        chmax(md[v],md[nv]+1);
    }
    if (md[v]==K&&par[v]!=0) ++ans,md[v]=0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i,N){
        int a; cin >> a; --a;
        if (i==0&&a!=0) ++ans,a=0;
        if (i!=0) G[a].push_back(i);
        par[i]=a;
    }
    dfs(0);
    cout << ans << endl;
}