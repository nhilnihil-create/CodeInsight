#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=1e18;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n,0){
        for(int i=0;i<n;i++) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[rx]<rank[ry]){
            par[rx]=ry;
        }else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[ry]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};

struct edge{
    int from,to;
    ll cost;
};

vector<edge> es(2000);
vector<ll> d(1000,INF);
vector<bool> negative(1000,false);
int n,m;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        es[i]=edge{a,b,-c};
    }
    d[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            edge e=es[j];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
            }
        }
    }
    ll ans=-d[n-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            edge e=es[j];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                negative[e.to]=true;
            }
            if(negative[e.from]) negative[e.to]=true;
        }
    }
    if(negative[n-1]) cout<<"inf"<<endl;
    else cout<<ans<<endl;
    return 0;
}