#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

// ダイクストラ法
// 参照：蟻本　p97
// O(mlogn)
struct edge{
    int to;
    ll cost;
};
typedef pair<int,int> P; // firstは最短距離、secondは頂点の番号
 
vector<edge> G[100010];
ll d[100010];
int n;
 
void dijkstra(int s){
    priority_queue<P,vector<P>, greater<P>> que;
    fill(d,d+n,1LL<<60);
    d[s]=0;
    que.push(P(0,s));
 
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        rep(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
 
int main(){
    cin>>n;
 
    rep(i,n-1){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--,b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    
    int q,k;
    cin>>q>>k;
    k--;
    dijkstra(k);
    rep(i,q){
        int x,y;
        cin>>x>>y;
        x--,y--;
        cout<<d[x]+d[y]<<endl;
    }
}