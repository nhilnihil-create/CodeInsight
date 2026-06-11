#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(16);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    for(ll i=0; i<n; i++) cin >> t[i];
    for(ll i=0; i<n; i++) cin >> a[i];

    vector<ll> lo(n, 1), hi(n, 1e9);
    lo[0] = hi[0] = t[0];
    lo[n-1] = max(lo[n-1], a[n-1]);
    hi[n-1] = min(hi[n-1], a[n-1]);
    for(ll i=0; i<n-1; i++) {
        if(t[i] < t[i+1]) {
            lo[i+1] = max(lo[i+1], t[i+1]);
            hi[i+1] = min(hi[i+1], t[i+1]);
        }
        if(a[n-1-i] < a[n-2-i]) {
            lo[n-2-i] = max(lo[n-2-i], a[n-2-i]);
            hi[n-2-i] = min(hi[n-2-i], a[n-2-i]);
        }
    }
    for(ll i=0; i<n; i++)
        hi[i] = min({hi[i], t[i], a[i]});

    ll r = 1;
    for(ll i=0; i<n; i++) {
        if(lo[i] > hi[i]) r = 0;
        (r *= hi[i] - lo[i] + 1) %= MOD;
    }
    cout << r << endl;
}
