#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q,k;
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main(){
    cin >> n;
    Graph G(n);
    for(ll i=0;i<n-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }
    cin >> q >> k;
    k--;
    queue<ll> que;
    vector<ll> dist(n,-1);
    que.push(k);
    dist[k]=0;
    while(!que.empty()){
        auto v=que.front();
        que.pop();
        for(auto nv:G[v]){
            if(dist[nv.to]!=-1) continue;
            que.push(nv.to);
            dist[nv.to]=dist[v]+nv.weight;
        }
    }
    for(ll i=0;i<q;i++){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        cout << dist[x]+dist[y] << endl;
    }
}  
