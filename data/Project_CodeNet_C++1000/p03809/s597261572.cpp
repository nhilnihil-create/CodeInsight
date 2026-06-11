#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> a;
vector<int> g[101010];
int root;

static const int INF = 0x3f3f3f3f;

int dfs(int v, int prev) {
        int sum = 0;
        int ma = -1;
        for (auto u : g[v]) {
                if (u == prev) continue;
                int get = dfs(u, v);
                ma = max(ma, get);
                sum += get;
        }
        if (ma == -1) return a[v];
        if (sum > 2 * a[v] || sum < a[v]) throw -1;
        int t = 2 * a[v] - sum;
        if (v == root) {
                if (t == 0) return INF;
                else throw -1;
        }
        if (sum >= 2 * ma) { 
                return t;
        } else {
                int possible = sum - ma;
                if (possible >= a[v] - t) return t;
                else throw -1;
        }
}

int main() {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i ++) cin >> a[i];
        for (int i = 0; i < n - 1; i ++) {
                int p, q;
                cin >> p >> q;
                p --, q --;
                g[p].push_back(q);
                g[q].push_back(p);
        }
        if (n == 2) {
                cout << (a[0] == a[1] ? "YES" : "NO") << endl;
                return 0;
        }
        for (int i = 0; i < n; i ++) if (g[i].size() != 1) {
                root = i;
                break;
        }
        //cerr << root << endl;
        try {
                if (dfs(root, -1) == INF) cout << "YES" << endl;
        }
        catch (int err) {
                cout << "NO" << endl;
                return 0; 
        }
        return 0;
}

