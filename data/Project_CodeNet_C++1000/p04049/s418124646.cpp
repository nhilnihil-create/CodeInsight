#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 1e5 + 21;

int n, k;
int ans;
vector <int> adj[MAXN];
int d[MAXN];

int bfs(int root, int j){
    queue <int> q;
    memset(d, -1, sizeof(d));
    d[root] = 0;
    q.push(root);
    
    if (j ^ -1) {
        d[j] = 0;
        q.push(j);
    }
    
    int node;
    int res = 0;

    while (!q.empty()){
        node = q.front();
        q.pop();
        res++;
        if (d[node] == (k / 2)) 
            continue;
        for (auto y: adj[node]){
            if (d[y] == -1){
                d[y] = d[node] + 1;
                q.push(y);
            }
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    if (k & 1) {
        for (int i = 1; i <= n; i++)
            for (auto y: adj[i])
                ans = max(ans, bfs(i, y));
    }
    else {
        for (int i = 1; i <= n; i++)
            ans = max(ans, bfs(i, -1));
    }
    cout << n - ans;
    return 0;
}
