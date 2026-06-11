#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve() {
    ll H, W, N, a, b;
    cin >> H >> W >> N;
    map<pair<ll, ll>, ll> m;
    ll ans[10];
    rep(i,10) ans[i] = 0;
    ans[0] = (H - 2) * (W - 2);
    rep(i, N) {
        cin >> a >> b;
        for (int v = a - 1; v < a + 2; v++) {
            if (v < 2 || v > H - 1) continue;
            for (int w = b - 1; w < b + 2; w++) {
                if (w < 2 || w > W - 1) continue;
                int black = 0;
                for (int x = v - 1; x < v + 2; x++) {
                    for (int y = w - 1; y < w + 2; y++) {
                        black += m[make_pair(x, y)];
                    }
                }
                ans[black]--;
                ans[black + 1]++;
            }
        }
        m[make_pair(a, b)] = 1;
    }
    rep(i,10) cout << ans[i] << endl;
    return;
}

int main() {
    solve();
}