#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) {if(a>b) {a=b;return true;} return false;}
const ll INF = 1LL<<60;
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
    vector<vector<ll>> A(N,vector<ll>(N));
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            cin >> A[i][j];
        }
    }
    vector<vector<ll>> B(N,vector<ll>(N));
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            B[i][j] = A[i][j];
        }
    }
    vector<vector<int>> C(N,vector<int>(N,1));
    for ( int k = 0; k < N; k++ ) {
        for ( int i = 0; i < N; i++ ) {
            for ( int j = 0; j < N; j++ ) {
                if ( i == k || j == k ) continue;
                ll d = B[i][k] + B[k][j];
                if ( d == A[i][j] ) C[i][j] = 0;
                else if ( d < A[i][j] ) {
                    return -1;
                }
                chmin( B[i][j], d );
            }
        }
    }

    ll ans = 0;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = i + 1; j < N; j++ ) {
            if ( B[i][j] != A[i][j] ) {
                return -1;
            }
            if ( C[i][j] == 1 ) ans += A[i][j];
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}