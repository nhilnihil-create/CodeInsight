#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int i, N;
    ll ans = 1e18, R = 0, L = 0;
    cin >> N;
    vector<ll> a(N);
    for(i=0; i<N; i++) {
        cin >> a[i];
        R += a[i];
    }

    for(i=0; i<N-1; i++) {
        L += a[i];
        R -= a[i];
        ans = min(ans, abs(R - L));
    }

    cout << ans << endl;
    return 0;
}