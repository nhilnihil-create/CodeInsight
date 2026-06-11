#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
        A[i]--;
    }
    ll ans = 0;
    for ( int i = 0; i < N; i++ ) {
        if ( A[A[i]] == i ) ans++;
    }
    ans /= 2;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}