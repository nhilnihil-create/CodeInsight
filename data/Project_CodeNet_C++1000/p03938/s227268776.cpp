#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ASSERT(C, ...) assert( (C) || (PRINT(__VA_ARGS__), false) )
template <class Head> void PRINT(Head head) {
    std::cout << head << "\n";
}
template <class Head, class... Tail> void PRINT(Head head, Tail... tail) {
    std::cout << head << " ";
    PRINT(tail...);
}

ll solve() {
    ll N;
    cin >> N;
    vector<ll> P(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> P[i];
        P[i]--;
    }
    vector<ll> da(N, 1), db(N, 1);
    for ( int i = 0; i < N; i++ ) {
        int p = P[i];
        if ( p < N-1 ) {
            da[p+1] += N-i;
        }
        if ( p > 0 ) {
            db[p-1] += N-i;
        }
    }
    vector<ll> a(N), b(N);
    ll sa = 0, sb = 0;
    for ( int i = 0; i < N; i++ ) {
        sa += da[i];
        a[i] = sa;
    }
    for ( int i = N-1; i >= 0; i-- ) {
        sb += db[i];
        b[i] = sb;
    }
    // for ( int i = 1; i < N; i++ ) {
    //     ASSERT(a[P[i-1]]+b[P[i-1]] < a[P[i]]+b[P[i]], i);
    // }

    for ( int i = 0; i < N; i++ ) {
        cout << (i != 0 ? " " : "") << a[i];
    }
    cout << "\n";
    for ( int i = 0; i < N; i++ ) {
        cout << (i != 0 ? " " : "") << b[i];
    }
    cout << "\n";
    return 0;
}

int main() {
    solve();
    return 0;
}