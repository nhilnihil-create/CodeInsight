#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int solve() {
    int N, M, a, b, d;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for ( int i = 0; i < M; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<int> V(Q), C(Q);
    priority_queue<pii> D;
    for ( int i = 0; i < Q; i++ ) {
        cin >> V[i] >> d >> C[i];
        V[i]--;
        D.push(pii(d, i));
    }
    int DMAX = 10;
    vector<vector<int>> col(DMAX+1, vector<int>(N, -1));
    int d0 = 0;
    for ( int d = DMAX; d >= 0 ; d-- ) {
        while ( !D.empty() && D.top().first >= d ) {
            int j = D.top().second;
            D.pop();
            if ( col[d][V[j]] < j ) col[d][V[j]] = j;
        }
        if ( d == 0 ) break;
        for ( int v = 0; v < N; v++ ) {
            col[d-1][v] = col[d][v];
        }
        for ( int v = 0; v < N; v++ ) {
            for ( int u : G[v] ) {
                if ( col[d-1][u] < col[d][v] ) col[d-1][u] = col[d][v];
            }
        }
    }
    for ( int v = 0; v < N; v++ ) {
        int a = col[0][v] >= 0 ? C[col[0][v]] : 0;
        cout << a << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}