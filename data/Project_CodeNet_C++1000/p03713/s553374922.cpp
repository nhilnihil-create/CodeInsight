#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const long long MOD = 1e9 + 7;
const int INF = 1e9 + 7;

ll solve(ll H, ll W) {
    vector<ll> diffs;
    ll h1 = H / 3;
    h1--;
    for (int i = 0; i < 3; i++) {
        ll h = h1 + i;
        if (h <= 0 || h >= H) continue;
        ll a = h * W;
        ll b = (H - h) / 2 * W;
        ll c = H * W - a - b;
        if (b > 0) diffs.push_back(max({a, b, c}) - min({a, b, c}));
        b = W / 2 * (H - h);
        c = H * W - a - b;
        if (b > 0) diffs.push_back(max({a, b, c}) - min({a, b, c}));
    }
    return *min_element(diffs.begin(), diffs.end());
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    cout << min(solve(H, W), solve(W, H)) << endl;
}