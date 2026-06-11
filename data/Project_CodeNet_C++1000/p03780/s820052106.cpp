#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) {
        cin >> a[i];
    }
    bool dpl[n + 1][k], dpr[n + 1][k];
    fill(dpl[0], dpl[n + 1], false);
    fill(dpr[0], dpr[n + 1], false);
    dpl[0][0] = dpr[n][0] = true;
    rep(i, n) {
        rep(j, k) {
            dpl[i + 1][j] |= dpl[i][j];
            if (j - a[i] < 0) continue;
            dpl[i + 1][j] |= dpl[i][j - a[i]];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        rep(j, k) {
            dpr[i][j] |= dpr[i + 1][j];
            if (j - a[i] < 0) continue;
            dpr[i][j] |= dpr[i + 1][j - a[i]];
        }
    }
    int ans = 0;
    rep(i, n) {
        vector<int> b, c;
        rep(j, k) {
            if (dpl[i][j]) b.emplace_back(j);
            if (dpr[i + 1][j]) c.emplace_back(j);
        }
        rep(j,b.size()){
            auto itr = lower_bound(ALL(c), k - a[i] - b[j]);
            if (itr == c.end()) continue;
            if (*itr < k - b[j]) {
                ans++;
                break;
            }
        }
    }
    cout << n - ans << endl;
    return 0;
}