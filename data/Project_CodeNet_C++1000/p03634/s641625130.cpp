#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int limit=100010;
struct Edge{
    int to,cost;
    Edge(int to,int cost):to(to),cost(cost) {}
};
vector<Edge> tree[limit];
int depth[limit];

void dfs(int o,int k,int d){
    depth[k]=d;
    for(auto &v:tree[k]){
        if(v.to==o)continue;
        dfs(k,v.to,d+v.cost);
    }
}

signed main(){
    int N;cin>>N;
    REP(i,N-1){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        tree[a].pb({b,c});
        tree[b].pb({a,c});
    }
    int Q,K;cin>>Q>>K;K--;
    dfs(-1,K,0);
    REP(i,Q){
        int x,y;cin>>x>>y;x--;y--;
        cout<<depth[x]+depth[y]<<endl;
    }
}