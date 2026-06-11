#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, Ma, Mb, a,b,c;
    cin >> N >> Ma >> Mb;
    vector<ll> A(N), B(N), C(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i] >> B[i] >> C[i];
    }
    int INF = 1e8;
    int V = 10000, Z = V/2;
    vector<vector<int>> dp(N+1, vector<int>(V, INF));
    auto val = [&](int a, int b) {
        return Mb * a - Ma * b;
    };
    for ( int i = 1; i <= N; i++ ) {
        int v = val(A[i-1],B[i-1]);
        int c = C[i-1];
        dp[i][Z+v] = c;
        for ( int x = 0; x < V; x++ ) {
            dp[i][x] = min(dp[i][x], dp[i-1][x]);
            if ( x-v >= 0 && x-v < V ) dp[i][x] = min(dp[i][x], dp[i-1][x-v] + c);
        }
    }
    ll ans = dp[N][Z];
    if ( ans >= INF ) ans = -1;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}