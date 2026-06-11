#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
using ll=int_fast64_t;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double EPS=1e-9;
const int MOD=1e9+7;
struct UnionFind{
    vector<int> par,dep;
    UnionFind(int n){
        dep.assign(n,0);
        par.assign(n,0);
        for(int i=0;i<n;i++)par[i]=i;
    }
    int find(int x){
        if(par[x]==x){
            return x;
        }else{
            return par[x]=find(par[x]);
        }
    }
    bool unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)return false;
        if(dep[u]>dep[v]){
            par[v]=u;
        }else if(dep[u]<=dep[v]){
            par[u]=v;
            if(dep[u]==dep[v]){
                dep[v]++;
            }
        }
        return true;
    }
};
vector<int> col;
vector<vector<int>> G;
bool dfs(int i,int c,int p){
    if(col[i]!=-1){
        if(c==col[i]){
            return true;
        }else{
            return false;
        }
    }
    bool res=true;
    col[i]=c;
    for(auto e:G[i]){
        if(e==p)continue;
        res&=dfs(e,c^1,i);
    }
    return res;
}
int main(){
    ll n,m;cin>>n>>m;
    UnionFind uf(n);
    G.resize(n);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;--u;--v;
        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u,v);
    }
    vector<ll> s(n,0);
    for(int i=0;i<n;i++){
        s[uf.find(i)]++;
    }
    ll ans=n*n;
    ll c1=0LL,c2=0LL,s1=0LL,s2=0LL;
    col.resize(n,-1);
    for(int i=0;i<n;i++){
        if(s[i]>=2LL){
            if(!dfs(i,0,-1)){
                ans-=s[i]*s[i]-1LL;
                ans-=((s1+s2)*s[i]-(c1+c2))*2LL;
                s1+=s[i];
                c1+=1LL;
            }else{
                ans-=s[i]*s[i]-2LL;
                ans-=((s1*s[i]-c1)+(s2*s[i]-c2*2LL))*2LL;
                s2+=s[i];
                c2+=1LL;
            }
        }
    }
    cout<<ans<<endl;
}