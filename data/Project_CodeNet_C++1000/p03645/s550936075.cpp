#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using Graph = vector<vector<int>>;

const int INF = 2e9;

int main(){
    int n,m;
    cin >> n >> m;
    Graph g(n + 1);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n+1,-1);
    queue<int> que;
  	que.push(1);
    dist[1] = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int nv : g[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    if(dist[n] == 2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}