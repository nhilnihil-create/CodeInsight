#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct UnionFind {
        int n;
        vector<int> parent;
        vector<int> rank;
        vector<int> num;
        int find(int x) {
                if (parent[x] == x) return  x;
                return parent[x] = find(parent[x]);
        }
        UnionFind(int n_) {
                n = n_;
                parent.resize(n);
                for (int i = 0; i < n; i ++) parent[i] = i;
                rank.assign(n, 0);
                num.assign(n, 1);
        }
        void unite(int x, int y) {
                if ((x = find(x)) != (y = find(y))) {
                        if (rank[x] < rank[y]) {
                                parent[x] = y;
                                num[y] += num[x];
                        } else {
                                parent[y] = x;
                                if (rank[x] == rank[y]) rank[x] ++;
                                num[x] += num[y];
                        }
                        n --;
                }
        }
        bool same(int x, int y) { return find(x) == find(y); }
        int get() { return n; }
        int get(int x) { return num[find(x)]; }
};

int main() {
        int n, k, l;
        scanf("%d%d%d", &n, &k, &l);
        UnionFind uf1(n), uf2(n);
        for (int i = 0; i < k; i ++) {
                int a, b;
                scanf("%d%d", &a, &b);
                a --, b --;
                uf1.unite(a, b);
        }
        for (int i = 0; i < l; i ++) {
                int a, b;
                scanf("%d%d", &a, &b);
                a --, b --;
                uf2.unite(a, b);
        }
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i ++) p[i] = make_pair(uf1.find(i), uf2.find(i));
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i ++) {
                pair<int, int> q = make_pair(uf1.find(i), uf2.find(i));
                int ans = upper_bound(p.begin(), p.end(), q) - lower_bound(p.begin(), p.end(), q);
                printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
        }
        return 0;
}

