#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N, sa = 0;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
        sa += A[i];
    }
    ll nn = N*(N+1)/2;
    if ( sa % nn != 0 ) return false;
    ll k = sa / nn;
    for ( int i = 0; i < N; i++ ) {
        ll d = - ( A[(i+1)%N] - A[i] - k );
        if ( d < 0 || d % N != 0 ) return false;
    }
    return true;
}

int main() {
    string ans = solve() ? "YES" : "NO";
    cout << ans << "\n";
    return 0;
}