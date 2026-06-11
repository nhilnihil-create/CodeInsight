#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    for ( int n = 0; n < N; n++ ) {
        for ( int m = 0; m < M; m++ ) {
            cin >> A[n][m];
        }
    }

    auto check = [&](ll k) {
        vector<int> ix(N);
        vector<int> num(M+1);
        vector<int> ng(M+1);
        for ( int n = 0; n < N; n++ ) {
            num[A[n][0]]++;
        }
        for(;;) {
            bool ok = true;
            for ( int m = 1; m <= M; m++ ) {
                if ( num[m] > k ) {
                    ng[m]++;
                    ok = false;
                }
            }
            if ( ok ) return true;
            for ( int n = 0; n < N; n++ ) {
                while ( ng[A[n][ix[n]]] > 0 ) {
                    num[A[n][ix[n]]]--;
                    ix[n]++;
                    if ( ix[n] >= M ) return false;
                    num[A[n][ix[n]]]++;
                }
            }
        }
        return false;
    };

    ll l = 0, r = N+1;
    while ( r - l > 1 ) {
        ll m = (l+r)/2;
        if ( check(m) ) r = m;
        else l = m;
    }
    return r;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}