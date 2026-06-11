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

    int lsearch(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = siz;

        if (node[k] > x || r <= a || b <= l)
            return b;
        if (k >= siz - 1)
            return k - (siz - 1);
        int vl = lsearch(a, b, x, 2 * k + 1, l, (l + r) / 2);
        if (vl != b)
            return vl;
        return lsearch(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }

    int rsearch(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = siz;

        if (node[k] >= x || r <= a || b <= l)
            return a - 1;
        if (k >= siz - 1)
            return k - (siz - 1);
        int vr = rsearch(a, b, x, 2 * k + 2, (l + r) / 2, r);
        if (vr != a - 1)
            return vr;
        return rsearch(a, b, x, 2 * k + 1, l, (l + r) / 2);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    SegTree segtree(a);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        int l = segtree.rsearch(0, i, a[i]);
        int r = segtree.lsearch(i + 1, N, a[i]);
        ans += (ll)a[i] * (i - l) * (r - i);
    }

    cout << ans << '\n';
    return 0;
}
