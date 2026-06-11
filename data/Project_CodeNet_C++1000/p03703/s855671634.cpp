#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

// Caution: 1-indexed
struct BIT {
    vector<ll> bit;
    int N;

    BIT(int N) : bit(vector<ll>(N + 1, 0)), N(N) {}

    // return sum in [0, `i`] in log(n)
    ll sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i - (i & -i));
    }

    // add `x` at `i`
    void add(int i, ll x) {
        if (i > N) return;
        bit[i] += x;
        add(i + (i & -i), x);
    }
};

const int maxn = 2e5;
ll b[maxn + 1], c[maxn + 1];

int main() {
    int n, k;
    cin >> n >> k;
    rep(i, n) {
        int a;
        cin >> a;
        b[i + 1] = b[i] + a - k;
        c[i + 1] = b[i + 1];
    }

    // 座標圧縮
    sort(c, c + n + 1);
    for (int i = 0; i <= n; i++) {  //b[i] <- index of b[i] in c
        int inf = 0, sup = n + 1;
        while (sup - inf > 1) {
            int mid = (inf + sup) / 2;
            if (c[mid] <= b[i])
                inf = mid;
            else
                sup = mid;
        }
        b[i] = sup;
    }

    BIT fwt(n + 10);
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += fwt.sum(b[i] + 1);
        fwt.add(b[i] + 1, 1);
    }
    cout << ans << endl;
}