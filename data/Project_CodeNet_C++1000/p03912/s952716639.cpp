#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n, m;
    cin >> n >> m;
    int x[n];
    map<int, int> mp;
    rep(i, 0, n) {
        cin >> x[i];
        mp[x[i]]++;
    }
    vector<int> md(m, 0), cnt(m, 0);
    for (auto it : mp) {
        int idx = it.first % m;
        md[idx] += it.second;
        cnt[idx] += it.second / 2;
    }
    int ans = md[0] / 2;
    rep(i, 1, (m + 1) / 2) {
        // cout << ans << "\n";
        ans += min(md[i], md[m - i]);
        int amari = abs(md[i] - md[m - i]);
        if (md[i] > md[m - i]) {
            ans += min(cnt[i], amari / 2);
        } else {
            ans += min(cnt[m - i], amari / 2);
        }
    }
    if (m % 2 == 0) {
        ans += md[m / 2] / 2;
    }
    cout << ans << "\n";
}