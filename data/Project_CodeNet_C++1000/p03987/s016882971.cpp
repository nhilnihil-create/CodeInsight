#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, a;
    cin >> N;
    vector<ll> ra(N);
    for ( ll i = 0; i < N; i++ ) {
        cin >> a;
        a--;
        ra[a] = i;
    }
    ll ans = 0;
    set<ll> s;
    for ( ll a = 0; a < N; a++ ) {
        ll i = ra[a];
        s.insert(i);
        auto p = s.find(i);
        ll l = ( p!=s.begin() ? *prev(p) : -1);
        ll r = ( next(p)!=s.end() ? *next(p) : N);
        ans += (i-l)*(r-i)*(a+1);
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}