#include "bits/stdc++.h"
using namespace std;
typedef long long li;

li n;
vector<vector<li>> g;

li grundy(li pos, li parent) {
    li res = 0;
    for (li next : g[pos]) {
        if (next == parent) {
            continue;
        }
        res ^= grundy(next, pos) + 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    g = vector<vector<li>>(n);
    for (int i = 0; i < n - 1; ++i) {
        li x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << (grundy(0, -1) == 0 ? "Bob" : "Alice") << endl;
    return 0;
}