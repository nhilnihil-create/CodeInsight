#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

struct Edge {
    ll from;
    ll to;
    ll w;
};

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<Edge> es(M);
    ll a, b, c;
    for ( int i = 0; i < M; i++ ) {
        cin >> a >> b >> c;
        a--, b--;
        es[i] = Edge{a, b, c};
    }
    vector<ll> d(N, -INF);
    d[0] = 0;
    for ( int n = 0; n < N; n++ ) {
        for ( auto e : es ) {
            if ( d[e.from] == -INF ) continue;
            d[e.to] = max(d[e.to], d[e.from] + e.w );
        }
    }
    ll d1 = d[N-1];
    for ( int n = 0; n < N; n++ ) {
        for ( auto e : es ) {
            if ( d[e.from] == -INF ) continue;
            d[e.to] = max(d[e.to], d[e.from] + e.w );
        }
    }
    if ( d1 < d[N-1] ) return INF;
    return d1;
}

int main() {
    auto ans = solve();
    if ( ans == INF ) cout << "inf" << "\n";
    else cout << ans << "\n";
    return 0;
}