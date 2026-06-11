#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, L, Q, a, b, xp, x;
    cin >> N;
    vector<ll> DX(N-1);
    for ( int i = 0; i < N; i++ ) {
        cin >> x;
        if ( i > 0 ) DX[i-1] = x - xp;
        xp = x;
    }
    cin >> L >> Q;
    vector<int> A(Q), B(Q);
    for ( int i = 0; i < Q; i++ ) {
        cin >> a >> b;
        a--, b--;
        A[i] = a, B[i] = b;
    }

    int logN = 0, t = 1;
    while ( t < N ) {
        logN++;
        t *= 2;
    }
    logN++;
    vector<vector<int>> next(logN, vector<int>(N-1));
    int nx = 0;
    ll len = 0;
    for ( int i = 0; i < N-1; i++ ) {
        while ( nx < N-1 && len + DX[nx] <= L ) {
            len += DX[nx];
            nx++;
        }
        next[0][i] = nx;
        len -= DX[i];
    }
    for ( int j = 0; j + 1 < logN; j++ ) {
        for ( int i = 0; i < N-1; i++ ) {
            if ( next[j][i] >= N-1 ) next[j+1][i] = N-1;
            else next[j+1][i] = next[j][next[j][i]];
        }
    }

    auto can_move = [&](int from, int to, int days) -> bool {
        int p = from;
        int j = 0;
        while ( days > 0 ) {
            if ( p >= N-1 ) break;
            if ( days & 1 ) {
                p = next[j][p];
            }
            days >>= 1;
            j++;
        }
        return p >= to;
    };

    auto get_days = [&](int a, int b) -> int {
        if ( a == b ) return 0;
        if ( a > b ) swap(a,b);
        int l = 0, r = N-1, m;
        while ( r - l > 1 ) {
            m = (l + r) / 2;
            if ( can_move(a,b,m) ) r = m;
            else l = m;
        }
        return r;
    };

    for ( int i = 0; i < Q; i++ ) {
        int d = get_days(A[i],B[i]);
        cout << d << "\n";
    }
    
    return 0;
}

int main() {
    solve();
    return 0;
}