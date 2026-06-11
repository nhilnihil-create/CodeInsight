#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct SegmentTree {
    SegmentTree(vector<int> v, int ini) {
        int sz = v.size();
        n = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1, ini);

        for (int i = 0; i < sz; i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = node[2 * i + 1] + node[2 * i + 2];
        }
    }

    void update(int k, int val) {
        k += n - 1;
        node[k] = val;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    int query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;

        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return node[k];

        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }

private:
    int n;
    vector<int> node;
};

map<ll, int> compress(vector<ll> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<ll, int> mp;
    for (int i = 0; i < (int)v.size(); i++) {
        mp[v[i]] = i;
    }
    return mp;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    vector<ll> b(N + 1, 0);
    for (ll i = 0; i <= N; i++) {
        b[i] = a[i] - i * K;
    }

    auto compressed = compress(b);
    int n = compressed.size();

    SegmentTree st(vector<int>(n, 0), 0);
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        int idx = compressed[b[i]];
        ans += st.query(0, idx + 1);
        int cur = st.query(idx, idx + 1);
        st.update(idx, cur + 1);
    }

    cout << ans << endl;
}
