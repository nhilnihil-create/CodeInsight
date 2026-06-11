#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
        vector<int> rank, p;
    
    DisjointSet() {}
    DisjointSet(int size) {
        rank.resize(size, 0);
        p.resize(size, 0);
        for (int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x) {
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y) {
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y) {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }

    int findSet(int x) {
        if (x != p[x]) {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

int main() {
    int N, K, L;
    scanf("%d %d %d", &N, &K, &L);
    DisjointSet ds_p = DisjointSet(N);
    DisjointSet ds_r = DisjointSet(N);
    int p, q, r, s;
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &p, &q);
        p--;
        q--;
        ds_p.unite(p, q);
    }
    for (int i = 0; i < L; i++) {
        scanf("%d %d", &r, &s);
        r--;
        s--;
        ds_r.unite(r, s);
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < N; i++) {
        mp[make_pair(ds_p.findSet(i), ds_r.findSet(i))]++;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", mp[make_pair(ds_p.findSet(i), ds_r.findSet(i))]);
    }
    printf("\n");
    return 0;
}