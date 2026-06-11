#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    int W[2], q;
    cin >> W[0] >> W[1];
    vector<pair<int, int>> p(0);
    rep(i, 2) {
        rep(j, W[i]) {
            cin >> q;
            p.push_back(make_pair(q, i));
            //cout << q << " " << i << endl;
        }
    }
    sort(p.begin(), p.end());
    int r[2];
    r[0] = 0;
    r[1] = 0;
    ll ans = 0;
    rep(i, W[0] + W[1]) {
        int x = p[i].first, y = p[i].second;
        ans += (W[1 - y] - r[1 - y] + 1L) * x;
        //cout << x << " " << y << " " << ans << endl;
        r[y]++;
    }
    cout << ans << endl;
}