#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll INF = 1000000000000000000;

struct edge{
    ll to ,cost;
};

vector<vector<edge>> g(100005);
vector<ll> depth(100005);

void dfs(int v ,int p ,ll d){
    depth[v] = d;
    for(auto &e : g[v]){
        if(e.to == p) continue;
        dfs(e.to ,v ,d + e.cost);
    }
}

int main(){
    ll n;
    cin >> n;
    for(int i=0;i<(n-1);i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back(edge{b ,c});
        g[b].push_back(edge{a ,c});
    }
    ll q ,k;
    cin >> q >> k;
    k--;

   /* queue<edge> que;
    vector<ll> d(n ,INF);
    que.push(edge{k ,0});
    d[k] = 0;
    while(!que.empty()){
        edge e = que.front();
        que.pop();
        for(int i=0;i<g[e.to].size() ;i++){
            ll ne = g[e.to][i].to ,nc = g[e.to][i].cost;
            if(d[ne] > d[e.to] + nc){
                d[ne] = d[e.to] + nc;
                que.push(edge{ne ,nc});
            }
        }
    }*/
    dfs(k ,-1 ,0);

    for(int i=0;i<q;i++){
        int x ,y;
        cin >> x >> y;
        x--; y--;
        cout << depth[x] + depth[y] << endl;
    }
}
