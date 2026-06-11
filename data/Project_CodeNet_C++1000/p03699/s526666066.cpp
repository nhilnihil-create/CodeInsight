#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll dis(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> s(n);
    ll sum = 0;
    rep(i, n){
        cin >> s[i];
        sum += s[i];
    }

    if (sum % 10 != 0){
        cout << sum << endl;
        return 0;
    }

    sort(s.begin(), s.end());

    rep(i, n){
        if (s[i] % 10 != 0){
            cout << (sum - s[i]) << endl;
            return 0;
        }
    }
    
    cout << 0 << endl;
    return 0;
}
