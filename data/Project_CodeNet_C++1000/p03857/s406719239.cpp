#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007,INF=1001001001;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


//#define int ll

int n,k,l,a,b;
int ans[200020];
vint visit[200020];

struct UF{
    vector<int>par,sz;
    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

signed main(){
    cin>>n>>k>>l;
    UF X,Y;
    X.init(n);Y.init(n);
    rep(i,0,k){
        cin>>a>>b;a--,b--;
        X.unite(a,b);
    }
    rep(i,0,l){
        cin>>a>>b;a--,b--;
        Y.unite(a,b);
    }
    
    rep(i,0,n)visit[X.find(i)].pb(i);
    rep(i,0,n){
        map<int,int>cnt;
        for(auto u:visit[i])cnt[Y.find(u)]++;
        for(auto u:visit[i])ans[u]=cnt[Y.find(u)];
    }
    
    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<" "<<endl;
    
    return 0;
}