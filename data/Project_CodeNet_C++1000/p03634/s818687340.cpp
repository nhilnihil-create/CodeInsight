#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

struct edge{int to; ll cost;};

vector<edge>tree[100010];
vector<ll>dist;

void dfs(int v, int p, ll d){
    dist[v]=d;
    for(edge u:tree[v]){
        if(u.to==p)continue;
        dfs(u.to,v,d+u.cost);
    }
}

int main(){
    int n;
    cin>>n;
    dist.resize(n);
    rep(i,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        a--; b--;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    int q,k;
    cin>>q>>k;
    k--;
    dfs(k,-1,0);
    vector<int>x(q),y(q);
    rep(i,q){
        cin>>x[i]>>y[i];
        x[i]--; y[i]--;
    }
    rep(i,q){
        cout<<dist[x[i]]+dist[y[i]]<<endl;
    }
    return 0;
}