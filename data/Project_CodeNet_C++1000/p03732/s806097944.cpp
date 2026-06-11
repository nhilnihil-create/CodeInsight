#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 105;
ll ans, sum, n, m, w, v, a, b, c, d;
ll va[N], vb[N], vc[N], vd[N];
ll pa[N], pb[N], pc[N], pd[N];

// w, 1, 2, 3
int main() {
    cin >> n >> m;
    cin >> w >> v;
    ll w0 = w, w1 = w + 1, w2 = w + 2, w3 = w + 3;
    va[a++] = v;
    for (int i = 1; i < n; ++i) {
        cin >> w >> v;
        if (w == w0)
            va[a++] = v;
        else if (w == w1)
            vb[b++] = v;
        else if (w == w2)
            vc[c++] = v;
        else
            vd[d++] = v;
    }
    sort(va, va + N, greater<ll>());
    sort(vb, vb + N, greater<ll>());
    sort(vc, vc + N, greater<ll>());
    sort(vd, vd + N, greater<ll>());
    for (int i = 0; i < a; ++i) {
        pa[i + 1] = pa[i] + va[i];
    }
    for (int i = 0; i < b; ++i) {
        pb[i + 1] = pb[i] + vb[i];
    }
    for (int i = 0; i < c; ++i) {
        pc[i + 1] = pc[i] + vc[i];
    }
    for (int i = 0; i < d; ++i) {
        pd[i + 1] = pd[i] + vd[i];
    }
    for (int h = 0; h <= a; ++h) {
        for (int i = 0; i <= b; ++i) {
            for (int j = 0; j <= c; ++j) {
                for (int k = 0; k <= d; ++k) {
                    if (w0 * h + w1 * i + w2 * j + w3 * k <= m) {
                        ans = max(ans, pa[h] + pb[i] + pc[j] + pd[k]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
