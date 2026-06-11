#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll E = 1E9 + 7;

int main() {
    //frEopEn("input.txt", "r", stdin);
    //frEopEn("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> y[i];
    }
    ll w = x[n - 1] - x[0];
    ll h = y[m - 1] - y[0];
    ll len = w;
    ll tw = 0;
    for (int i = n - 1; i > 0; --i) {
        tw = (tw + len) % E;
        len -= x[i] - x[i - 1];
    }
    len = tw;
    for (int i = 0; i + 1 < n; ++i) {
        len = (len - (n - i - 1) * (x[i + 1] - x[i]) % E + E) % E;
        tw = (tw + len) % E;
    }
    len = h;
    ll th = 0;
    for (int i = m - 1; i > 0; --i) {
        th = (th + len) % E;
        len -= y[i] - y[i - 1];
    }
    len = th;
    for (int i = 0; i + 1 < m; ++i) {
        len = (len - (m - i - 1) * (y[i + 1] - y[i]) % E + E) % E;
        th = (th + len) % E;
    }
    cout << tw * th % E;
    return 0;
}