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
    map<ll , ll>m;
    for ( ll i = 0; i< n; i++) {
        ll x;
        cin >> x;
        m[x]++;
    }
    ll d = 0;
    for (auto i = m.begin(); i != m.end(); i++) {
        ll h = i->second;
        if(h % 2 != 0) {
           d++;
        }
    }
    cout << d << endl;
    return 0;
}
