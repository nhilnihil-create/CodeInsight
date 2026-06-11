#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define long long long

int main(void) {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(auto &e: a) cin >> e;

    vector<ll> b(n, 2e9);

    ll r = 1e18;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++)
            b[j] = min(b[j], a[(j+n-i)%n]);
        ll s = 0;
        for(ll j=0; j<n; j++)
            s += b[j];
        r = min(r, s + i*x);
    }
    cout << r << endl;
}
