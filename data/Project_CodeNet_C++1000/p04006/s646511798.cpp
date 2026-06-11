#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

ll solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    ll ans = INF;
    for ( int m = 0; m < N; m++ ) {
        ll t = 0;
        for ( int i = 0; i < N; i++ ) {
            t += A[i];
        }
        t += m * X;
        if ( ans > t ) ans = t;
        ll az = A[N-1];
        for ( int i = N-1; i >= 1; i-- ) {
            A[i] = min(A[i], A[i-1]);
        }
        A[0] = min(A[0], az);
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}