#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

struct SegTree {
    int siz;
    vector<int> node;

    SegTree(vector<int> &v) : siz(1) {
        int N = v.size();
        while (siz < N)
            siz *= 2;
        node.resize(2 * siz - 1, INT_MAX);

        for (int i = 0; i < N; ++i)
            node[i + siz - 1] = v[i];
        for (int i = siz - 2; i >= 0; --i)
            node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int k, int x) {
        k += siz - 1;
        node[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    int query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = siz;

        if (r <= a || b <= l)
            return INT_MAX;
        if (a <= l && r <= b)
            return node[k];
        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    SegTree segtree(a);
    ll ans = LLONG_MAX;
    for (int i = 0; i < N; ++i) {
        ll tmp = (ll)i * x;
        for (int j = 0; j < N; ++j) {
            int l = j - i, r = j + 1;
            if (l < 0) {
                l += N;
                tmp += min(segtree.query(l, N), segtree.query(0, r));
            } else
                tmp += segtree.query(l, r);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
