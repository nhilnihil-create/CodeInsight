#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    for ( int i = 0; i <= N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( i*j + (N-i)*(M-j) == K) return true;
        }
    }
    return false;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}