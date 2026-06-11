#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    vector<ll> a;
    for (auto p : mp) {
        if (p.second >= 4) for (int i = 0; i < 2; ++i) a.emplace_back(p.first);
        else if (p.second >= 2) a.emplace_back(p.first);
    }
    sort(a.rbegin(), a.rend());
    if (a.size() < 2) cout << 0 << endl;
    else cout << a[0] * a[1] << endl;
}
