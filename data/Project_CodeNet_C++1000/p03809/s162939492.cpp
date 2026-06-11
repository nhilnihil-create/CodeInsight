#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;

vector<long long int> a, b;
vector<vector<int>> graph;
bool flag = true;

int DFS(int v, int parent_v){
    if(b[v] != -INF) return b[v];

    long long int sum = 0;
    for(int child_v : graph[v]){
        if(child_v == parent_v) continue;

        DFS(child_v, v);
        sum += b[child_v];
    }
    // a[v] = b[v] + (sum - b[v]) / 2
    b[v] = 2 * a[v] - sum;

    if(b[v] < 0) flag = false;
    if((sum - b[v]) % 2 != 0) flag = false;

    long long int leakage = 0;
    for(int child_v : graph[v]){
        if(child_v == parent_v) continue;

        leakage += max(0LL, b[child_v] - (sum - b[v])/2);
    }
    if(leakage > b[v]) flag = false;

    //cout << "b[" << v+1 << "] = " << b[v] << endl;
    return b[v];
}

int main(){
    int n;
    cin >> n;

    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    graph.resize(n);
    vector<int> degree(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;

        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] += 1;
        degree[v] += 1;
    }

    int root = -1;
    b.assign(n, -INF);
    for(int i=0; i<n; i++){
        if(degree[i] == 1) b[i] = a[i];
        else root = i;
    }
    if(root == -1){// tree with leaves only = o--o
        if(n == 2 && a[0] == a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }

    DFS(root, -1);
    if(flag == false || b[root] != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}