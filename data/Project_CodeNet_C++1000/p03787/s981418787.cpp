#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
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
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int N,M;
int A[222222],B[222222];
vint G[111111];

int col[111111];
bool dfs(int v,int c){
    col[v]=c;
    for(auto u:G[v]){
        if(col[u]!=-1){
            if(col[u]==c)return false;
        }
        else if(!dfs(u,1-c))return false;
    }
    return true;
}

signed main(){
    cin>>N>>M;
    UnionFindTree uf(N);
    rep(i,M){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
        G[A[i]].pb(B[i]);
        G[B[i]].pb(A[i]);
        uf.unite(A[i],B[i]);
    }

    memset(col,-1,sizeof(col));
    int a=0,b=0,k=0;
    rep(i,N){
        if(uf.find(i)!=i)continue;
        if(uf.size(i)==1)k++;
        else{
            if(dfs(i,0))b++;
            else a++;
        }
    }

    cout<<a*a+2*a*b+2*b*b+2*N*k-k*k<<endl;
    return 0;
}
