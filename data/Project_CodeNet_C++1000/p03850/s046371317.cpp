#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), OP(N);
    char op;
    OP[0] = 1;
    cin >> A[0];
    for ( int i = 1; i < N; i++ ) {
        cin >> op >> A[i];
        OP[i] = op == '+' ? 1 : -1;
    }
    ll s_all = 0, ss = 0, cn = 0;
    vector<ll> b(N);
    for ( int i = 0; i < N; i++ ) {
        s_all += A[i];
        if ( OP[i] < 0 ) cn++;
        ss += A[i] * OP[i];
    }
    if ( cn <= 1 ) {
        return ss;
    }
    ll s = 0;
    vector<ll> r(N); // 逆向き、-までの和
    for ( int i = N-1; i >= 0; i-- ) {
        s += A[i];
        if ( OP[i] < 0 ) {
            r[i] = s;
            s = 0;
        }
    }
    ll ans = - (1LL << 60), pn = 0;
    for ( int i = 0; i < N; i++ ) {
        if ( OP[i] < 0 ) {
            ans = max(ans, s_all - pn * 2 - r[i] * 2);
            pn += A[i];
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}