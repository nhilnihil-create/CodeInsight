#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mx = 10000007;
const ll MOD = 1e9 + 7;
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
int main() {
    ll n;
    cin >> n;

    vector<ll>v;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    ll ans = v[0];

    for (ll i = 0; i < n; i++) {
        ans = lcm(ans, v[i]);
    }
    cout << ans << endl;
}
