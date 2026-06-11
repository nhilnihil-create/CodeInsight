#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define long long long

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &e: a) cin >> e;

    ll r = 0, t = 0;
    for(ll i=0; i<n; i++) {
        ll s = max(0ll, (a[i]-(t+1) + t) / (t+1));
        r += s;
        if(a[i] == t+1) t++;
        if(!t) t=1;
    }
    cout << r << endl;
}
