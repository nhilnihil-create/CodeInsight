#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w, h;
    cin >> w >> h;
    vector<ll> p(w), q(h), s(h + 2);
    ll ans = 0;
    rep(i, 0, w) {
        cin >> p[i];
        ans += p[i];
    }
    rep(i, 0, h) {
        cin >> q[i];
        ans += q[i];
    }

    sort(q.begin(), q.end());
    rep(i, 1, h + 1) s[i] = s[i - 1] + q[i - 1];

    for (auto x : p) {
        int i = lower_bound(q.begin(), q.end(), x) - q.begin() - 1;
        ans += s[i + 1] + (h - i - 1) * x;
    }
    cout << ans << endl;

    return 0;
}
