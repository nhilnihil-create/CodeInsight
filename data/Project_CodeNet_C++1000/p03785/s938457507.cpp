#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<pair<ll, ll>> T;
    rep(i, n) {
        int t;
        cin >> t;
        T.push_back(make_pair(t, t+k));
    }
    sort(T.begin(), T.end());
    ll ans = 0;
    ll l = 0;
    ll r = 30000000000;
    ll count = 0;
    rep(i, n) {
        l = max(l, T[i].first);
        r = min(r, T[i].second);
        if (l > r) {
            ans++;
            l = T[i].first;
            r = T[i].second;
            count = 0;
        }
        else if (count == c) {
            ans++;
            count = 0;
            l = T[i].first;
            r = T[i].second;
        }
        if (i == n-1) {
            ans++;
        }
        count++;
    }
    cout << ans << endl;

}