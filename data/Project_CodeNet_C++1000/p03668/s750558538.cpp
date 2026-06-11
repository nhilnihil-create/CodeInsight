#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> adj[N];

int dfs(int u, int par)
{
    int gr = 0;
    for (auto v : adj[u])
        if (v!=par)
            gr ^= dfs(v, u);
    return 1 + gr;
}

int main()
{
  //  ios::sync_with_stdio(0);
  //  cin.tie(0);

    int t;
    t=1;

    while(t--) {
        fill(adj, adj+N, vector<int>());

        int n;
        cin>>n;

        for (int i=1; i<n; i++) {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int gr = dfs(1, -1) - 1;
        cout<<(gr ? "Alice\n" : "Bob\n");
    }
}
