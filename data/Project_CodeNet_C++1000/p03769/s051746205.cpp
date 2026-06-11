#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    ll n = N+1;
    ll a = 1, b = 1;
    while ( (1LL << (a+1)) < n ) a++;

    auto log_2_lower = [](ll n) {
        ll r = 0;
        while ( 1LL << (r+1) <= n ) r++;
        return r;
    };

    int lc = log_2_lower(n);
    vector<int> rcs;
    for ( int i = 0; i < 50; i++ ) {
        if ( (n >> i) & 1 )  rcs.push_back(i);
    }
    vector<int> t1, t2;
    for ( int i = 0; i < lc; i++ ) {
        if ( (n >> i) & 1 ) {
            t1.push_back( 2*lc - i );
        }
        t1.push_back(i+1);
    }

    vector<int> ans;
    for ( int i = 0; i < t1.size(); i++ ) {
        if ( t1[i] <= lc ) ans.push_back(t1[i]);
    }
    for ( int i = t1.size()-1; i >= 0; i-- ) {
        if ( t1[i] > lc ) ans.push_back(t1[i]);
    }
    for ( int i = 0; i < t1.size(); i++ ) {
        ans.push_back(t1[i]);
    }

    cout << ans.size() << "\n";
    for ( int i = 0; i < ans.size(); i++ ) {
        cout << (i != 0 ? " " : "") << ans[i];
    }
    cout << "\n";

    return 0;
}

int main() {
    solve();
    return 0;
}