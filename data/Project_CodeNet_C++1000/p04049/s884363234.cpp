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

const int MAX_N=2010;

int N,K,ans=0,e=0;
vector<vector<int>> G(MAX_N);
vector<vector<int>> d(MAX_N,vector<int>(MAX_N));
vector<int> cnt(MAX_N,1);
vector<int> cnt2(MAX_N,0);

void dfs(int v,int p,int r,int &c){
    for (auto nv:G[v]){
        if (nv==p) continue;
        d[r][nv]=d[r][v]+1;
        if (d[r][nv]<=K/2) ++cnt[r];
        if (K%2==1&&d[r][nv]==(K+1)/2) ++c;
        dfs(nv,v,r,c);
    }
    if (p==r) chmax(cnt2[r],c),c=0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i,N-1){
        int a,b; cin >> a >> b; --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,N) d[i][i]=0;
    rep(i,N) dfs(i,-1,i,e),chmax(ans,cnt[i]+cnt2[i]);
    cout << N-ans << endl;
}