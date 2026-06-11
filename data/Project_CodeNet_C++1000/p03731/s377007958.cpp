#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    ll n, t;
    cin >> n >> t;
    ll ans = t;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 1; i < n; i++) {
        ans += min(v[i] - v[i-1], t);
    }
    cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
