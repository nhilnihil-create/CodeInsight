#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

ll solve(ll W, ll H) {
    ll mi = min(W, H);
    for (ll i = 1; i < W; i++) {
        ll wi = W - i;
        ll C1 = i * H;
        ll C2 = wi*(H/2);
        ll C3 = wi*((H/2) + (H%2 == 1));
        ll sma = max({C1,C2,C3});
        ll smi = min({C1,C2,C3});
        mi = min(mi, sma - smi);
    }
    return mi;
}
int main() {
    ll H, W; cin >> H >> W;
    if (H % 3 == 0 || W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << min(solve(W, H), solve(H, W)) << endl;
}
