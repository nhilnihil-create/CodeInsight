#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> T(N), A(N);
    for ( int i = 0; i < N; i++ ) cin >> T[i];
    for ( int i = 0; i < N; i++ ) cin >> A[i];
    ll m = 0;
    for ( int i = 0; i < N; i++ ) {
        m = max(m, T[i]);
        m = max(m, A[i]);
    }
    int it = 0, ia = N-1;
    for ( int i = 0; i < N; i++ ) {
        if ( T[i] == m ) {
            it = i;
            break;
        }
    }
    for ( int i = N-1; i >= 0; i-- ) {
        if ( A[i] == m ) {
            ia = i;
            break;
        }
    }
    for ( int i = it; i < N; i++ ) {
        if ( T[i] != m ) return 0;
    }
    for ( int i = ia; i >= 0; i-- ) {
        if ( A[i] != m ) return 0;
    }
    if ( it > ia ) return 0;
    const ll MOD = 1e9 + 7;
    auto Add = [&](ll& x, ll y) { x = ( x % MOD + y % MOD ) % MOD; };
    auto Mul = [&](ll& x, ll y) { x = ( x % MOD * y % MOD ) % MOD; };
    ll ans = 1;
    for ( int i = 1; i < N-1; i++ ) {
        if ( T[i] != T[i-1] || A[i] != A[i+1] ) continue;
        Mul(ans, min(T[i], A[i]));
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}