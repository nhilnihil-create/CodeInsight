#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    int a, b;
    vector<vector<int>> G(N);
    for ( int i = 0; i < N-1; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    function<ll(int,int)> dfs = [&](int v, int p) {
        if ( p != -1 && G[v].size() == 1 ) {
            return A[v];
        } else {
            // x = 2*A - sum(ch),  x >= 0, A <= sum(ch)
            ll s = 0;
            for ( int u : G[v] ) {
                if ( u == p ) continue;
                ll y = dfs(u, v);
                if ( y < 0 ) return -1LL;
                if ( y > A[v] ) return -1LL;
                s += y;
            }
            if ( A[v] > s ) return -1LL;
            ll x;
            if ( p == -1 && G[v].size() == 1 ) {
                x = A[v] - s;
            } else {
                x = 2*A[v] - s;
            }
            if ( x < 0 ) return -1LL;
            return x;
        }
    };
    
    bool ans = (dfs(0,-1) == 0LL);
    return ans;
}

int main() {
    string ans = solve() ? "YES" : "NO";
    cout << ans << "\n";
    return 0;
}