#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <utility>
using namespace std;

using P = pair<int, int>;

struct UnionFind {
    vector<int> parent;
    int set_num;

    UnionFind(int n) {
        parent.resize(n, -1);
        set_num = n;
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (size(x) < size(y)) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            set_num--;
        }
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    int find(int x) {
        if (parent[x] < 0) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    int size(int x) {
        return -parent[find(x)];
    }

    int size() {
        return set_num;
    }
};

array<int, 300000> group1, group2;

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    UnionFind uf1(N), uf2(N);
    for (int i = 0; i < K; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        uf1.unite(p, q);
    }

    for (int v = 0; v < N; v++) {
        group1[v] = uf1.find(v);
    }

    for (int i = 0; i < L; i++) {
        int r, s;
        cin >> r >> s;
        r--; s--;
        uf2.unite(r, s);
    }

    for (int v = 0; v < N; v++) {
        group2[v] = uf2.find(v);
    }

    map<P, int> counter;
    for (int v = 0; v < N; v++) {
        counter[make_pair(group1[v], group2[v])]++;
    }
    for (int v = 0; v < N; v++) {
        cout << counter[make_pair(group1[v], group2[v])] << " ";
    }
    cout << endl;

    return 0;
}
