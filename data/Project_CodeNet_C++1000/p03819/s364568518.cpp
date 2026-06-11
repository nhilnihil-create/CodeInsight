#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegmentTree {

    int sz;
    vector< vector<int> > t;

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vl == vr) {
            t[v].push_back(a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        merge(t[2 * v + 1].begin(), t[2 * v + 1].end(), t[2 * v + 2].begin(), t[2 * v + 2].end(), back_inserter(t[v]));
    }

    int query(int v, int vl, int vr, int l, int r, int k) const {
        if (r < vl || vr < l)
            return 0;
        if (l <= vl && vr <= r)
            return t[v].end() - upper_bound(t[v].begin(), t[v].end(), k);
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r, k);
        int qr = query(2 * v + 2, vm + 1, vr, l, r, k);
        return ql + qr;
    }

public:

    SegmentTree(const vector<int> &a) {
        sz = a.size();
        t.resize(4 * sz);
        build(0, 0, sz - 1, a);
    }

    int query(int l, int r, int k) const {
        return query(0, 0, sz - 1, l, r, k);
    }

};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> m >> n;
    vector<pair<int, int>> segs(m);
    for (int i = 0; i < m; ++i) {
        cin >> segs[i].first >> segs[i].second;
    }
    sort(segs.begin(), segs.end());
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        a[i] = segs[i].second;
    }
    SegmentTree t(a);
    for (int i = 1; i <= n; ++i) {
        ll s = 0;
        for (int j = i; j <= n; j += i) {
            int pos1 = lower_bound(segs.begin(), segs.end(), make_pair(j - i + 1, 0)) - segs.begin();
            int pos2 = lower_bound(segs.begin(), segs.end(), make_pair(j + 1, 0)) - segs.begin() - 1;
            if (pos1 <= pos2) {
                s += t.query(pos1, pos2, j - 1);
            }
        }
        cout << s << '\n';
    }
    return 0;
}