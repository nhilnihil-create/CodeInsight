#include"bits/stdc++.h"

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll MOD = 1e9 + 7;
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))

int main() {
    ll n, x;
    cin >> n;
    map<ll, ll>m;

    for (ll i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }

    vector<ll>v;

    for (auto i = m.begin(); i != m.end(); i++) {
        if(i->second >= 2) {
            i->second /= 2;
            while (i->second) {
                v.push_back(i->first);
                i->second--;
            }
        }
    }


    sort(v.begin(), v.end(), greater <ll>());
    if (v.size() < 2) {
        puts("0");
        return 0;
    }

   ll ans = v[0] * v[1];
   
    cout << ans << endl;
    return 0;
}
