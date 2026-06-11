#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> d;
vector<bool> visited;

void DFS(int v, int dist){
    if(visited[v] == true) return ;
    visited[v] = true;
    d[v] = min(d[v], dist);

    for(int adjacent : graph[v]){
        if(visited[adjacent] == true) continue;

        DFS(adjacent, dist+1);
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> edge(n-1);
    graph.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;

        graph[a].push_back(b);
        graph[b].push_back(a);
        edge[i] = {a,b};
    }

    int ans = n;
    if(k % 2 == 0){
        for(int i=0; i<n; i++){
            d.assign(n,n+1);// n+1 = INF
            visited.assign(n,false);
            DFS(i,0);

            int count = 0;
            for(int j=0; j<n; j++){
                //cout << d[j] << " ";
                if(d[j] > k/2) count += 1;
            }
            //cout << endl;
            ans = min(ans, count);
        }
    }
    if(k % 2 == 1){
        for(int i=0; i<n-1; i++){
            d.assign(n,n+1);// n+1 = INF
            visited.assign(n,false);
            DFS(edge[i].first,0);
            visited.assign(n,false);
            DFS(edge[i].second,0);

            int count = 0;
            for(int j=0; j<n; j++){
                //cout << d[j] << " ";
                if(d[j] > k/2) count += 1;
            }
            //cout << endl;
            ans = min(ans, count);
        }
    }
    cout << ans << endl;
    return 0;
}