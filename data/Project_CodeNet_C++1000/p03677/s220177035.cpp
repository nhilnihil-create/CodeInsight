#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, p, q, f = 0, g = 0, r = 0, s = 0, a[100005] = {};
    ll z = mod * 328ll, u = 0, v = 0, w = 0;
    ll x[100005] = {}, y[200005] = {}, t[100005] = {};
    vector<pii> b, c, d, e;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (a[i + 1] > a[i]) b.push_back({a[i], a[i + 1]}), u += a[i + 1] - a[i];
        else c.push_back({a[i], a[i + 1] + m}), v += a[i + 1] - a[i] + m;
    }
    p = (int)b.size(); q = (int)c.size();
    for (int i = 0; i < p; i++) d.push_back({b[i].first + 1, 1}), d.push_back({b[i].second, b[i].first - b[i].second});
    sort(d.begin(), d.end());
    for (int i = 1; i <= m; i++) {
        u -= r;
        x[i] = u;
        while (f < p + p && d[f].first <= i) {
            if (d[f].second == 1) r++;
            else {
                u -= d[f].second + 1;
                r--;
            }
            f++;
        }
    }
    for (int i = 0; i < q; i++) e.push_back({c[i].first + 1, 1}), e.push_back({c[i].second, c[i].first - c[i].second});
    sort(e.begin(), e.end());
    for (int i = 1; i <= m + m; i++) {
        w += s;
        y[i] = w;
        while (g < q + q && e[g].first <= i) {
            if (e[g].second == 1) s++;
            else {
                w += e[g].second + 1;
                s--;
            }
            g++;
        }
    }
    for (int i = 1; i <= m; i++) t[i] = v - y[i] - y[i + m];
    for (int i = 1; i <= m; i++) z = min(z, x[i] + t[i]);
    cout << z;
}
