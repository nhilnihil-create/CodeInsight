#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    for ( int i = 0; i < N; i++ ) {
        ll xmax = A + (N-1-i)*D - i*C;
        ll xmin = A + (N-1-i)*C - i*D;
        if ( xmin <= B && B <= xmax ) return true;
    }
    return false;
}

int main() {
    string ans = solve() ? "YES" : "NO";
    cout << ans << "\n";
    return 0;
}