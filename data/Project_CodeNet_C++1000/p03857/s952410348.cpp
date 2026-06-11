#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n) {
        REP(i, n) par[i] = i;
    }

    int root(int x) {
        if (x == par[x]) return x;
        else return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (x < y) swap(x, y);
        par[x] = y;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k, l;
    cin >> n >> k >> l;

    UnionFind D(n), R(n);

    REP(i, k) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        D.unite(p, q);
    }

    REP(i, l) {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        R.unite(r, s);
    }

    map<pair<int, int>, int> mp;

    REP(i, n) {
        mp[make_pair(D.root(i), R.root(i))]++;
    }

    REP(i, n) {
        if (i)cout << " ";
        cout << mp[make_pair(D.root(i), R.root(i))];
    }
    cout << endl;

    return 0;
}