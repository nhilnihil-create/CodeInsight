#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n; cin >> n;
    ll m = (n + 1) % 2;
    map<ll, ll> mp;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        ll num; num = a[i];
        if (num % 2 != m) {
            cout << 0 << endl;
            return 0;
        }
        mp[num]++;
    }

    bool isok = true;
    ll prev = -1;
    pair<ll, ll> fe = *mp.begin();
    if (!((fe.first == 0 && n % 2 == 1 && fe.second == 1) || (fe.first == 1 && n % 2 == 0 && fe.second == 2))) {
        cout << 0 << endl;
        return 0;
    }
    for (auto elem : mp) {
        if (elem.first == 0 || elem.second == 1) {
            prev = elem.first;
            continue;
        }
        if (elem.second != 2) {
            cout << 0 << endl;
            return 0;
        }
        if (elem.first - prev != 2) {
            cout << 0 << endl;
            return 0;
        }
        prev = elem.first;
    }

    ll ans = 1;
    for (size_t i = 1; i <= n / 2; i++)
    {
        ans = (ans * 2) % (ll)(1e9+7);
    }
    cout << ans << endl;
    
    return 0;
}