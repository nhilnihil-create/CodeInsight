#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll n, t, x;
    cin >> n >> t;
    vector<ll>v;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    ll s = t;
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
            ll z = abs(v[i+1]- v[i]);
        if(z < t) {
            ans += z;
        }
        else {
            ans += t;
        }

    }
    cout << ans + t << endl;
    return 0;
}
