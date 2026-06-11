#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr ll mod = 1000000007;

ll n, x, a[2000], b[10000];

ll btr(ll l, ll r, ll i) {
    if (r - l == 1) return b[i] = a[l];
    b[i] = min(btr(l, (l + r) / 2, i * 2), btr((l + r) / 2, r, i * 2 + 1));
    return b[i];
}

ll rmq_(ll l, ll r, ll i, ll ql, ll qr) {
    if (ql <= l && qr >= r) return b[i];
    ll m = (l + r) / 2;
    ll v = 2000000000;
    if (ql < m) v = min(v, rmq_(l, m, i * 2, ql, qr));
    if (qr > m) v = min(v, rmq_(m, r, i * 2 + 1, ql, qr));
    return v;
}

ll rmq(ll l, ll r) {
    if (l >= r) return min(rmq_(0, n, 1, l, n), rmq_(0, n, 1, 0, r));
    else return rmq_(0, n, 1, l, r);
}

int main() {
    //fstream fs("/home/shinku/1_16.txt", ios_base::in);
    cin >> n >> x;
    for (ll i = 0; i < n; i++) cin >> a[i];
    btr(0, n, 1);
    ll r = INT64_MAX / 2;
    for (ll t = 0; t < n; t++) {
        ll c = t * x;
        for (ll s = 0; s < n; s++) {
            c += rmq((s - t + n) % n, (s + 1) % n);
        }
        r = min(r, c);
    }
    cout << r << endl;
}