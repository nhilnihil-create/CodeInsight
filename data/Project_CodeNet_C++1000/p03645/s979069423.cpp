#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

map<int, set<int>> G;
int N, M;
int dfs(int c, int p, int cnt) {
    if (cnt == 2) {
        if (c == N - 1) {
            return true;
        } else {
            return false;
        }
    }

    bool ok = false;
    for (auto x : G[c]) {
        if (x == p) continue;
        ok = ok || dfs(x, c, cnt + 1);
    }
    return ok;
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].insert(b);
        G[b].insert(a);
    }

    bool ok = dfs(0, -1, 0);
    if (ok) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    // for (auto x : G) {
    //     cout << "key: " << x.first << ", value: ";
    //     for (auto y : x.second) {
    //         cout << y << ", ";
    //     }
    //     cout << endl;
    // }
}