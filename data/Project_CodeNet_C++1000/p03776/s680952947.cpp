#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> V(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> V[i];
    }
    sort(V.begin(), V.end(),greater<>());
    ll s = 0;
    for ( int i = 0; i < A; i++ ) {
        s += V[i];
    }
    double m = s/(double)A;
    ll l = lower_bound(V.begin(), V.end(), V[A-1], greater<>()) - V.begin();
    ll r = upper_bound(V.begin(), V.end(), V[A-1], greater<>()) - V.begin();
    ll cr = r - l;
    ll cb = B - l;
    ll ca = A - l;
    ll d = 1;
    ll ans = 0;
    for ( ll i = 0; i < cb; i++ ) {
        d *= cr - i;
        d /= (i+1);
        if ( i+1 >= ca ) ans += d;
        if ( l != 0 && i+1 >= ca ) break;
    }

    cout << m << "\n";
    cout << ans << "\n";
    return 0;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}