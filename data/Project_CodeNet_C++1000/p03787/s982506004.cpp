#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int N, M, u, v;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for ( int i = 0; i < M; i++ ) {
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<int> col(N, -1);
    function<bool(int,int,int)> dfs = [&](int v, int p, int c) {
        if ( col[v] != -1 ) {
            if ( col[v] != c ) return false;
            else return true;
        }
        col[v] = c;
        bool bi = true;
        for ( int u : G[v] ) {
            if ( u == p ) continue;
            bool b = dfs(u, v, 1-c);
            bi = bi && b;
        }
        return bi;
    };

    ll iso = 0, con = 0, nb = 0;
    for ( int i = 0; i < N; i++ ) {
        if ( col[i] != -1 ) continue;
        if ( G[i].size() == 0 ) iso++;
        else {
            con++;
            if ( !dfs(i,-1,0) ) nb++;
        }
    }
    
    ll n = N;
    ll ans = (n*n-(n-iso)*(n-iso)) + con*con + (con-nb)*(con-nb);
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}