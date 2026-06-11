#include<bits/stdc++.h>

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

    vector<pair<ll, ll>>v, u;

    for (auto i = m.begin(); i != m.end(); i++) {
        if(i->second >= 2) {
            v.push_back({i->first, i->second});
        }
        if(i->second >= 4) {
            u.push_back({i->first, i->second});
        }
    }
   ll ans, ans1= 0;
    if(u.size() >= 1) {
    sort(u.begin(), u.end());
    reverse(u.begin(), u.end());
    ans1 = u[0].first * u[0].first;
   }
   if(v.size() > 1) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ans = v[0].first * v[1].first;
   }

   else if(v.size() == 1 && v[0].second >= 4 ) {
    ans = v[0].first * v[0].first;
   }
    else {
        ans = 0;
    }
    cout << max(ans, ans1) << endl;
    return 0;
}
