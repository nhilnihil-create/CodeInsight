//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


struct edge{
    ll to,w;
};

vector<ll> dep;
vector<vector<edge>> path;

void dfs(ll s,ll par){
    for(auto e:path[s]){
        if(e.to==par) continue;
        dep[e.to]=dep[s]+e.w;
        dfs(e.to,s);
    }
}

int main(){
    ll n; cin>>n;
    path.assign(n,vector<edge>(0));
    rep(i,n-1){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        path[a].push_back(edge{b,c});
        path[b].push_back(edge{a,c});
    }
    dep.assign(n,0);
    ll q,k; cin>>q>>k; k--;
    dfs(k,-1);
    rep(i,q){
        ll x,y; cin>>x>>y;
        x--; y--;
        printf("%lld\n",dep[x]+dep[y]);
    }
    
}