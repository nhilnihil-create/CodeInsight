#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

typedef long long ll;

const int Inf = 1e9;
const double EPS = 1e-9;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int bitCount(long bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    ll w1, v1;
    cin >> w1 >> v1;
    vector<ll> stuff[4];
    stuff[0].push_back(v1);
    rep (i, n - 1) {
        int w, v;
        cin >> w >> v;
        stuff[w - w1].push_back(v);
    }
    rep (i, 4) sort(stuff[i].begin(), stuff[i].end(), greater<int>());

    ll ans = 0;
    int i, j, k, l; 
    for (i = 0; i < stuff[0].size() + 1; ++i) {
        for (j = 0; j < stuff[1].size() + 1; ++j) {
            for (k = 0; k < stuff[2].size() + 1; ++k) {
                for (l = 0; l < stuff[3].size() + 1; ++l) {
                    ll tmp, value = 0;
                    tmp = w1 * i + (w1 + 1) * j + (w1 + 2) * k + (w1 + 3) * l;
                    if (tmp > w) continue;
                    rep (v, i) value += stuff[0][v];
                    rep (v, j) value += stuff[1][v];
                    rep (v, k) value += stuff[2][v];
                    rep (v, l) value += stuff[3][v];
                    ans = (ll)max(ans, value);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
