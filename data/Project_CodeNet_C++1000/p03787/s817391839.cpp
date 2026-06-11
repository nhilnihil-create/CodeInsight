#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> d;
vector<bool> visited;

bool DFS(int v, int previous_v = -1){
    if(visited[v] == true){
        if((d[previous_v] - d[v]) % 2 == 0) return true;
        else return false;
    }
    visited[v] = true;
    if(previous_v != -1) d[v] = d[previous_v] + 1;

    bool flag = false;
    for(int adjacent_v : graph[v]){
        if(adjacent_v == previous_v) continue;

        flag |= DFS(adjacent_v, v);
    }
    return flag;
}

int main(){
    long long int n, m;
    cin >> n >> m;

    graph.resize(n);
    vector<int> degree(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;

        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] += 1;
        degree[v] += 1;
    }

    long long int ans = 0;
    long long int a = 0, b = 0, c = 0;
    visited.assign(n, false);
    d.resize(n);

    for(int i=0; i<n; i++){
        if(degree[i] == 0){
            c += 1;
            ans += 2*n;
        }
        else if(visited[i] == false){
            bool odd_cycle = DFS(i);
            if(odd_cycle == false) a += 1;
            if(odd_cycle == true)  b += 1;
        }
    }
    ans -= c * c;

    ans += (a+b) * (a+b) + a * a;// 2 * a * a + 1 * ((a+b) * (a+b) - a * a);
    cout << ans << endl;
    return 0;
}