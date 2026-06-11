#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int solve() {
    int N, K, a, b;
    cin >> N >> K;
    vector<vector<int>> G(N);
    for ( int i = 0; i < N-1; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // v から距離 k-1, k 以内にある点の数
    function<pii(int,int,int)> dfs = [&](int v, int p, int k) {
        pii r;
        if ( k == 0 ) {
            r.second++;
        } else {
            r.first++;
            r.second++;
            for ( int u : G[v] ) {
                if ( u == p ) continue;
                auto x = dfs(u, v, k-1);
                r.first += x.first;
                r.second += x.second;
            }
        }
        return r;
    };

    int ans = 100000;
    if ( K % 2 == 0 ) {
        for ( int i = 0; i < N; i++ ) {
            pii x = dfs(i, -1, K / 2);
            ans = min(ans, N - x.second );
        }
    } else {
        for ( int i = 0; i < N; i++ ) {
            int s = 1, md = 0;
            for ( int j : G[i] ) {
                auto x = dfs(j, i, (K-1)/2 );
                s += x.first;
                md = max(md, x.second - x.first);
            }
            s += md;
            ans = min(ans, N - s );
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}