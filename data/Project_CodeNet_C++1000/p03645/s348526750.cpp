#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

vector<vector<int>> g;
// ダイクストラ法
// 参照：蟻本　p97
// O(mlogn)
struct edge{int to,cost;};
typedef pair<int,int> P; // firstは最短距離、secondは頂点の番号
 
vector<edge> G[200010];
int d[200010];
int n;
 
void dijkstra(int s){
    priority_queue<P,vector<P>, greater<P>> que;
    fill(d,d+n,INF);
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
    int k;
    cin>>n>>k;

    rep(i,k){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
 
    dijkstra(0);
    
    //cout<<d[n-1]<<endl;
    if(d[n-1]==2) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

}