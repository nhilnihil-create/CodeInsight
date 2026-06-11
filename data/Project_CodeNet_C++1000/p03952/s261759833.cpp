#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, X;
    cin >> N >> X;
    ll m = 2*N-1;
    if ( X == 1 || X == 2*N-1 ) {
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    vector<ll> A(2*N-1);
    if ( N == 2 ) {
        A[0] = 1, A[1] = 2, A[2] = 3;
    } else {
        queue<int> v;
        if ( X > 2 ) {
            A[N-2] = X-1;
            A[N-1] = X;
            A[N] = X+1;
            A[N+1] = X-2;
            for ( int i = 1; i < X-2; i++ ) v.push(i);
            for ( int i = X+2; i <= 2*N-1; i++ ) v.push(i);
        } else {
            A[N-2] = X+1;
            A[N-1] = X;
            A[N] = X-1;
            A[N+1] = X+2;
            for ( int i = 1; i < X-1; i++ ) v.push(i);
            for ( int i = X+3; i <= 2*N-1; i++ ) v.push(i);
        }
        for ( int i = 0; i < 2*N-1; i++ ) {
            if ( A[i] == 0 ) {
                A[i] = v.front();
                v.pop();
            }
        }
    }
    for ( int i = 0; i < 2*N-1; i++ ) {
        cout << A[i] << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}