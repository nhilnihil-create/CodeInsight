#include<bits/stdc++.h>
using namespace std;

void update(int v, int d, int c, vector<vector<int> > &adj, vector<vector<int> > &dp){

    if(dp[v][d] != 0) return;

    dp[v][d] = c;
    if(d == 0) return;

    update(v, d - 1, c, adj, dp);

    for(auto u : adj[v]){
        update(u, d - 1, c, adj, dp);
    }

    return;
}

int main(){

    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q; cin >> q;
    vector<int> v(q);
    vector<int> d(q);
    vector<int> c(q);
    for(int i = 0; i < q; i++){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    
    vector<vector<int> > dp(n, vector<int> (11, 0));
    
    for(int i = q - 1; i >= 0; i--){
        update(v[i], d[i], c[i], adj, dp);
    }

    for(int i = 0; i < n; i++) cout << dp[i][0] << endl;

    return 0;
}