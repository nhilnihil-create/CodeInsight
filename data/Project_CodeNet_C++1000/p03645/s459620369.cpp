#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    int n,m;
    cin >> n >> m;
    Graph G(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(n,-1);
    queue<int> que;
    
    dist[0] = 0;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int nv:G[v]){
            if(dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    if(dist[n-1] == 2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}