#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cout << fixed << setprecision(16);

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(auto &e: v) cin >> e;
    sort(v.begin(), v.end(), greater<>());
    ll ca = 0, cb = 0;
    ll x = v[a-1];
    for(ll i=0; i<a; i++)
        if(v[i] == x) ca++;
    for(ll i=a; i<n; i++)
        if(v[i] == x) cb++;

    double s = 1.0 * accumulate(v.begin(), v.begin()+a, 0ll) / a;
    cout << s << endl;

    if(v[0] == v[a-1]) {
        ll r = 0;
        for(ll k=a; k<=b; k++) {
            ll t = 1;
            // ca+cb C k
            for(ll i=0; i<k; i++)
                t *= ca+cb-i, t /= i+1;
            r += t;
        }
        cout << r << endl;
    } else {
        ll t = 1;
        // ca+cb C ca
        for(ll i=0; i<ca; i++)
            t *= ca+cb-i, t /= i+1;
        cout << t << endl;
    }

}
