#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 200010;
const int MOD = (int) 1e9 + 7;

class unionfind {
    int num;
    vector<int> par;
public:
    explicit unionfind(int n) : num(n), par(n, -1) {}

    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        num--;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size() { return num; }

    int size(int x) { return -par[find(x)]; }
};

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    unionfind uf_t(n), uf_r(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf_r.unite(a, b);
    }
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf_t.unite(a, b);
    }

    map<P, int> mp;
    for (int i = 0; i < n; ++i) {
        int root_r = uf_r.find(i), root_t = uf_t.find(i);
        mp[P(root_r, root_t)]++;
    }
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << " ";
        int root_r = uf_r.find(i), root_t = uf_t.find(i);
        cout << mp[P(root_r, root_t)];
    }
    cout << endl;
}
