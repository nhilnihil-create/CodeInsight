#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

using pii = pair<int, int>;

class disjoint_set {
private:
    std::vector<size_t> parents;
    std::vector<size_t> ranks;
    std::vector<size_t> component_sizes;
public:
    const size_t n_vertices;
    size_t n_components;

    disjoint_set(size_t n_vertices) : n_vertices(n_vertices), parents(n_vertices), ranks(n_vertices, 0), n_components(n_vertices), component_sizes(n_vertices, 1) {
        for (size_t i = 0; i < n_vertices; ++i) {
            parents[i] = i;
        }
    }

    size_t root(size_t x) {
        if (parents[x] == x) {
            return x;
        } else {
            return parents[x] = root(parents[x]);
        }
    }

    void merge(size_t x, size_t y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }
        if (ranks[x] < ranks[y]) {
            parents[x] = y;
            component_sizes[y] += component_sizes[x];
        } else {
            parents[y] = x;
            component_sizes[x] += component_sizes[y];
            if (ranks[x] == ranks[y]) {
                ++ranks[x];
            }
        }
        --n_components;
    }

    bool is_same(size_t x, size_t y) {
        return root(x) == root(y);
    }

    size_t component_size(size_t x) {
        return component_sizes[root(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K, L;
    cin >> N >> K >> L;

    disjoint_set ds1(N);
    REP(_, K) {
        int p, q;
        cin >> p >> q;
        --p;
        --q;
        ds1.merge(p, q);
    }

    disjoint_set ds2(N);
    REP(_, L) {
        int r, s;
        cin >> r >> s;
        --r;
        --s;
        ds2.merge(r, s);
    }

    map<pii, int> cnt;
    REP(i, N) {
        cnt[pii(ds1.root(i), ds2.root(i))]++;
    }

    REP(i, N) {
        cout << cnt[pii(ds1.root(i), ds2.root(i))] << " ";
    }
    cout << endl;

    return 0;
}
