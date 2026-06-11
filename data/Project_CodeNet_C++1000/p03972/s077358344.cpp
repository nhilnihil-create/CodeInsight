#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;

ll solve() {
    ll W, H, p;
    cin >> W >> H;
    vector<pii> PQ; // P:[0,W), Q:[W,W+H)
    for ( int i = 0; i < W+H; i++ ) {
        cin >> p;
        PQ.push_back(pii(p,i));
    }
    sort(PQ.begin(), PQ.end());
    ll w = W + 1, h = H + 1;
    ll ans = 0;
    for ( auto p : PQ ) {
        if ( p.second < W ) {
            ans += p.first * h;
            w--;
            if ( w == 0 ) break;
        } else {
            ans += p.first * w;
            h--;
            if ( h == 0 ) break;
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}