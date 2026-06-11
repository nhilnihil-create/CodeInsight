#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
const int N = 100100;

ll d[N], df[N], kek[N];

void update(int l, int r, ll x) {
    d[l] += x;
    d[r + 1] -= x + r - l;
    ++df[l];
    --df[r];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i && a[i] < a[i - 1]) {
            ll t = (a[i - 1] - a[i] + m - 1) / m;
            a[i] += t * m;
        }
    }
    ll s = a[n - 1] - a[0];
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] - a[i] < 2) {
            continue;
        }
        int l = (a[i] + 2) % m;
        int r = (a[i + 1]) % m;
        if (!l) {
            l += m;
        }
        if (!r) {
            r += m;
        }
        if (l > r) {
            update(l, m, 1);
            update(1, r, m - l + 2);
        } else {
            update(l, r, 1);
        }
    }
    ll ans = s;
    ll tmp = 0;
    for (int i = 1; i <= m; ++i) {
        tmp += df[i - 1];
        d[i] += tmp;
    }
    for (int i = 1; i <= m; ++i) {
        kek[i] = kek[i - 1] + d[i];
    }
    for (int i = 1; i <= m; ++i) {
        ans = min(ans, s - kek[i]);
    }
    cout << ans;
    return 0;
}